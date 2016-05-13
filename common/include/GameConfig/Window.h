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

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>
#include <GameConfig/Monitor.h>

using std::cout;
using std::endl;

class Window
{
public:
// Constructor and Destructor
	Window();
	~Window();
// Public Interface
	GLFWwindow * getGLFWwindowHandle() const;
    void displayGraphicalInfo() const;
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