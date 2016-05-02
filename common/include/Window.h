/*************************************************************************
* Window Class
*
* Class to contain and have full control over the GLFWwindow  
*
* User interacts with this to adjust 
*	toggle fullscreen/windowed mode
*	screen resolutions
*	aspect ratios
*	etc...
*
*************************************************************************/
#ifndef WINDOW_H_
#define WINDOW_H_

#define GLFW_DLL
#include <GL\glew.h>
#include <GL\glfw3.h>
#include <iostream>
#include <Monitor.h>

using std::cout;
using std::endl;

class Window
{
public:
// Friend class for callbacks
	friend class Game;
// Constructor and Destructor
	Window();
	~Window();
// Public Interface
	GLFWwindow * getGLFWwindowHandle();
	static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode);
	static void mouse_btn_callback(GLFWwindow * window, int button, int action, int mods);
	static void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos);
	static void monitor_callback(GLFWmonitor * monitor, int event);
private:
// Private (Internal) Interface
	void initGLFW();
	void setMonitorPrefs();
	void initGLEW();
	void setWindowHints();
	void toggleFullScreenMode();
	void setAllKeyCallbacks();
// Private Data Members
	Monitor _monitor;
	GLFWwindow * _glfwWindow;
	const char * _title;
	GLuint _height, _width;
	bool _fullscreenMode;
};

#endif