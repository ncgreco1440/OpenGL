#include <Game.h>
#include <GameConfig/Input.h>
#include <vector>
#include <utils/Timer.h>
#include <Layers/TileLayer.h>

#define TEST_50K_SPRITES 0

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
	shader.setUniform("light_pos", appm::vec2(4.5f, 1.5f));
	utils::Timer timer;
	graphics::TileLayer layer(&shader);
	std::vector<Renderable2D*> sprites;
	SRNG::fRandomGen<float> ranClr(0.0f, 1.0f);
#if TEST_50K_SPRITES
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			appm::vec4 newclr(ranClr.random_floating(), ranClr.random_floating(), ranClr.random_floating(), 1.0f);
			layer.add(new Sprite(x, y, 0.9f, 0.9f, newclr));
		}
	}
#else
	Sprite * button = new Sprite(-15.0f, 5.0f, 6.0f, 3.0f, appm::vec4(1, 1, 1, 1));
	layer.add(button);
	//layer.push(appm::mat4(button->getPosition));
	layer.add(new Sprite(0.5f, 0.5f, 5.0f, 2.0f, appm::vec4(1, 0, 1, 1)));
	//layer.pop();
#endif
	//layer.add(new Sprite(0, 0, 2, 2, appm::vec4(0.7f, 0.2f, 0.8f, 1.0f)));
	// Game Initialization
    while (!glfwWindowShouldClose(_window.getGLFWwindowHandle()))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader.setUniform("light_pos", appm::vec2((Input::m_xPos * 32.0f / 960.0f - 16.0f),
			(9.0f - Input::m_yPos * 18.0f / 540.0f)));
		layer.render();
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
