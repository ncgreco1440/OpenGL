#ifndef GAME_CONFIGURATION_H_
#define GAME_CONFIGURATION_H_

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>
#include <string>

namespace gcnfg
{
	namespace ASPECT_RATIO
	{
		extern const float FOUR_BY_THREE;
		extern const float SIXTEEN_BY_NINE;
		extern const float SIXTEEN_BY_TEN;
		extern const float TWENTY_BY_NINE;
	}

	extern const char * TITLE;
	extern int HEIGHT;
	extern int WIDTH;

	extern void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode);
	extern void mouse_btn_callback(GLFWwindow * window, int button, int action, int mods);
	extern void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos);
	extern void monitor_callback(GLFWmonitor * monitor, int event);

    extern void fatal_error(int errorCode, const std::string& errorMessage);
	//extern void fatal_error(int errorCode, const char * errorMessage);
}

#endif