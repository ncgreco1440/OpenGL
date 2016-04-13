#ifndef Gameconfig_h
#define Gameconfig_h

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>

namespace gconf
{
/**********************************************************!
* VARBIABLES
**********************************************************/
    extern const char * TITLE;
    extern const int HEIGHT;
    extern const int WIDTH;
    
/**********************************************************!
* FUNCTIONS
**********************************************************/
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    void mouse_callback(GLFWwindow* window, int button, int action, int mods);
};

#endif
