#include <GameConfig/config.h>

/*************************************************************************
* Aspect Ratio Constants
*************************************************************************/
const float gcnfg::ASPECT_RATIO::FOUR_BY_THREE = 1.3333f;
const float gcnfg::ASPECT_RATIO::SIXTEEN_BY_NINE = 1.7778f;
const float gcnfg::ASPECT_RATIO::SIXTEEN_BY_TEN = 1.6f;
const float gcnfg::ASPECT_RATIO::TWENTY_BY_NINE = 2.3333f;
/*************************************************************************
* Inital Game Configuration Variables
*************************************************************************/
const char * gcnfg::TITLE = "Game";
int gcnfg::HEIGHT = 640;
int gcnfg::WIDTH = (int)(640 * gcnfg::ASPECT_RATIO::FOUR_BY_THREE);
/*************************************************************************
* Input Callbacks
*************************************************************************/
/**********************************
* Key Callback
**********************************/
void gcnfg::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
/**********************************
* Mouse Button Callback
**********************************/
void gcnfg::mouse_btn_callback(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		std::cout << "Left Mouse button clicked at: (" << x << ", " << y << ")" << std::endl;
	}
}
/**********************************
* Cursor Position Callback
**********************************/
void gcnfg::cursor_pos_callback(GLFWwindow * window, double xpos, double ypos)
{
	//...
}
/**********************************
* Monitor Callback
**********************************/
void gcnfg::monitor_callback(GLFWmonitor * monitor, int event)
{
	if (event == GLFW_CONNECTED)
		std::cout << monitor << " was connected" << std::endl;
	if (event == GLFW_DISCONNECTED)
		std::cout << monitor << " was disconnected" << std::endl;
}
/*************************************************************************
* Fatal Error
*************************************************************************/
void gcnfg::fatal_error(int errorCode, const std::string& errorMessage)
{
	std::cout << "============\tERROR\t============" << std::endl;
	std::cerr << "*** " << errorMessage << std::endl;
	std::cerr << "*** " << errorCode << std::endl;
	std::cout << "====================================" << std::endl;
	exit(errorCode);
}

//extern void fatal_error(int errorCode, const char * errorMessage)
//{
//    std::cout << "============\tERROR\t============" << std::endl;
//    std::cerr << "*** " << errorMessage << std::endl;
//    std::cerr << "*** " << errorCode << std::endl;
//    std::cout << "====================================" << std::endl;
//    exit(errorCode);
//}