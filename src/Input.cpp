#include <GameConfig/Input.h>
#include <GameConfig/Window.h>

bool Input::k_buttons[1024] = {false};
bool Input::m_buttons[32] = {false};
double Input::m_xPos = 0.0;
double Input::m_yPos = 0.0;

void Input::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
    //Window * currentWindow = (Window*)glfwGetWindowUserPointer(window);
    Input::k_buttons[key] = action != GLFW_RELEASE;
}

void Input::mouse_btn_callback(GLFWwindow * window, int button, int action, int mods)
{
    //Window * currentWindow = (Window *)glfwGetWindowUserPointer(window);
    Input::m_buttons[button] = action != GLFW_RELEASE;
}

void Input::cursor_pos_callback(GLFWwindow * window, double xpos, double ypos)
{
    glfwGetCursorPos(window, &Input::m_xPos, &Input::m_yPos);
}

void Input::monitor_callback(GLFWmonitor * monitor, int event)
{
    
}

bool Input::isKeyPressed(unsigned int key)
{
    if(key > 1023)
        return false;
    return Input::k_buttons[key];
}

bool Input::isMousePressed(unsigned int btn)
{
    if(btn > 32)
        return false;
    return Input::m_buttons[btn];
}