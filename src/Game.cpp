#include <Game.h>
#include <GameConfig/Input.h>

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
    shader.setUniform("ml_matrix", appm::mat4::translation(appm::vec3(4, 3, 0.0)));
    
    Renderable2D sprite(appm::vec3(5, 5, 0), appm::vec2(4,4), appm::vec4(1, 0, 1, 1), shader);
    Renderable2D sprite2(appm::vec3(7, 1, 0), appm::vec2(2,3), appm::vec4(0.2f, 0, 1, 1), shader);
    Simple2DRenderer renderer;
    
    shader.setUniform("light_pos", appm::vec2(4.5f, 1.5f));
    shader.setUniform("colour", appm::vec4(0.0, 0.5, 1.0, 1.0));
    
    
	// Game Initialization
    while (!glfwWindowShouldClose(_window.getGLFWwindowHandle()))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
    
        shader.setUniform("light_pos", appm::vec2((Input::m_xPos * 16.0f / 960.0f),
                                                  (9.0f - Input::m_yPos * 9.0f / 540.0f)));
        
        renderer.submit(&sprite);
        renderer.submit(&sprite2);
        renderer.flush();
		update();
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
    cout << "Cursor at (" << Input::m_xPos << ", " << Input::m_yPos << ")" << endl;

	glfwSwapBuffers(_window.getGLFWwindowHandle());
}
