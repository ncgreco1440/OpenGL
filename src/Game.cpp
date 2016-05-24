#include <Game.h>
#include <GameConfig/Input.h>
#include <vector>
#include <utils/Timer.h>

#define BATCH_RENDERER 1

Game::Game()
{
	cout << "Game Created!" << endl;
	_window.displayGraphicalInfo();
}


Game::~Game()
{
	cout << "Game Destroyed!" << endl;
}


void Game::run()
{
    cout << "Game is running" << endl;
    
    Shader shader("Assets/Shaders/test.vert", "Assets/Shaders/test.frag");
    shader.enable();
    appm::mat4 ortho = appm::mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    shader.setUniform("pr_matrix", ortho);
//    appm::mat4 model = appm::mat4::rotation(-55.0f, appm::vec3(1.0f, 0.0f, 0.0f));
//    appm::mat4 view = appm::mat4::translation(appm::vec3(0.0f, 0.0f, -5.0f));
//    appm::mat4 proj = appm::mat4::perspective(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    
    std::vector<Renderable2D*> sprites;
    SRNG::fRandomGen<float> ranClr(0.0f, 1.0f);
  
    for(float y = 0; y < 9.0f; y+=0.9)
    {
        for(float x = 0; x < 16.0f; x+= 0.9)
        {
         appm::vec4 newclr(ranClr.random_floating(), ranClr.random_floating(), ranClr.random_floating(), 1.0f);
            sprites.push_back(new
#if BATCH_RENDERER
        Sprite(x, y, 0.9f, 0.9f, newclr));
#else
        StaticSprite(x, y, 0.9f, 0.9f, newclr, shader));
#endif
        }
    }


#if BATCH_RENDERER
    Render renderer;
#else
    Simple2DRenderer renderer;
#endif
    
    shader.setUniform("light_pos", appm::vec2(4.5f, 1.5f));
    shader.setUniform("colour", appm::vec4(0.0, 0.5, 1.0, 1.0));

	utils::Timer timer;
	// Game Initialization
    while (!glfwWindowShouldClose(_window.getGLFWwindowHandle()))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
		
		appm::mat4 mat = appm::mat4::translation(appm::vec3(5, 5, 5));
		mat = mat * appm::mat4::rotation(timer.elapsed() * 50.0f, appm::vec3(0, 0, 1));
		mat = mat * appm::mat4::translation(appm::vec3(-5, -5, -5));

		shader.setUniform("ml_matrix", mat);
        shader.setUniform("light_pos", appm::vec2((Input::m_xPos * 16.0f / 960.0f),
                                                  (9.0f - Input::m_yPos * 9.0f / 540.0f)));
#if BATCH_RENDERER
        renderer.begin();
#endif
		for (auto sp : sprites)
			renderer.submit(sp);
        
#if BATCH_RENDERER
        renderer.end();
#endif
        renderer.flush();
		update();
		timer();
    }
	cout << "Game has exited as requested by the player" << endl;
}

void Game::update()
{
    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
        std::cout << "OpenGL Error! " << error << std::endl;
    
    if(Input::isKeyPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(_window.getGLFWwindowHandle(), GL_TRUE);
    if(Input::isKeyPressed(GLFW_KEY_A))
        cout << "A button is pressed!" << endl;
    if(Input::isMousePressed(GLFW_MOUSE_BUTTON_1))
        cout << "Mouse button 1 is pressed!" << endl;
    //cout << "Cursor at (" << Input::m_xPos << ", " << Input::m_yPos << ")" << endl;

	glfwSwapBuffers(_window.getGLFWwindowHandle());
    glfwSwapInterval(0);
}
