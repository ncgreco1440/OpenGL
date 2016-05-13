#ifndef INPUT_H_
#define INPUT_H_

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glfw3.h>

class Input
{
public:
    static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode);
    static void mouse_btn_callback(GLFWwindow * window, int button, int action, int mods);
    static void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos);
    static void monitor_callback(GLFWmonitor * monitor, int event);
    
    static bool isKeyPressed(unsigned int key);
    static bool isMousePressed(unsigned int btn);
    
    static bool k_buttons[1024];
    static bool m_buttons[32];
    static double m_xPos, m_yPos;
};


#endif