#include "Gameconfig.h"

/**********************************************************!
 * VARIABLES
 **********************************************************/
const char * gconf::TITLE = "Game Engine";
const int gconf::HEIGHT = 480;
const int gconf::WIDTH = HEIGHT * 1.78;

/**********************************************************!
 * FUNCTIONS
 **********************************************************/
void gconf::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)          //exit application with 'esc' key
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void gconf::mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        std::cout << "You pressed the mouse button at (" << x << ", " << y << ")" << "!" << std::endl;
    }
}