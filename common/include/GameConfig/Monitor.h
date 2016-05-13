#ifndef MONITOR_H_
#define MONITOR_H_

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>


class Monitor
{
public:
// Constructors and Destructor
	Monitor() :_glfwMonitor(0), _videoMode(0), _gammaRamp(0), 
		_phys_height(0), _phys_width(0), _res_height(0),
		_res_width(0), _dpi(0) {};
	~Monitor() {};
// Public Interface
	void initMonitor();
	void printMonitorStats() const;
	GLFWmonitor * getGLFWmonitorHandle() const { return _glfwMonitor; };
	int getRefreshRate() const { return _videoMode->refreshRate; };
	int getScrResWidth() const { return _res_width; };
	int getSrcResHeight() const { return _res_height; };
private:
// Private Data Members
	GLFWmonitor * _glfwMonitor;
	const GLFWvidmode * _videoMode;
	const GLFWgammaramp * _gammaRamp;
	const char * _name;
	int _phys_height;
	int _phys_width;
	int _res_height;
	int _res_width;
	double _dpi;
};

#endif