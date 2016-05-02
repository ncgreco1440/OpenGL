#include <Window.h>
#include <GameConfig/config.h>

Window::Window():_glfwWindow(0), _title(gcnfg::TITLE)
{
	// Initialize GLFW
	initGLFW();
	// Set Window Hints
	setWindowHints();
	// Initialize GLEW
	initGLEW();
	// Successful completion of Window Creation
	cout << "Window Object Created!" << endl;
}

Window::~Window()
{
	glfwTerminate();
	cout << "Window Object Destroyed!" << endl;
}

GLFWwindow * Window::getGLFWwindowHandle()
{
	return _glfwWindow;
}

void Window::initGLFW()
{
	// Step 1) Initialize GLFW else, fatal_error
	if (!glfwInit())
		gcnfg::fatal_error(-1, "GLFW Initialization has failed, Program Terminated with exit code -1");

	// Step 2) Use GLFW Error Callbacks from now on
	glfwSetErrorCallback(gcnfg::fatal_error);

	// Step 3) Initialize the Monitor
	_monitor.initMonitor();

	// Step 4) Create the GLFW Window
	_glfwWindow = glfwCreateWindow(_monitor.getScrResWidth(), _monitor.getSrcResHeight(), 
		_title, _monitor.getGLFWmonitorHandle(), nullptr);

	// Step 5) Confirm GLFW Window was successfully created
	if (_glfwWindow == 0)
	{
		glfwTerminate();
		gcnfg::fatal_error(-1, "GLFW Window Creation has failed, Program Terminated with exit code -1");
	}

	// Step 6) Make the _window member the current context of this game
	glfwMakeContextCurrent(_glfwWindow);
	glfwSetWindowUserPointer(_glfwWindow, this);

	// Step 7) Set up Input Callback functions
	setAllKeyCallbacks();
}

void Window::initGLEW()
{
	// GLEW Initialization
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		gcnfg::fatal_error(-1, "GLEW Initialization has failed, Program Terminated with exit code -1");
	}

	// Set inital color of the window
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

void Window::setWindowHints()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void Window::toggleFullScreenMode()
{
	GLFWwindow * tmpWindow;
	// Create a temp window
	if (!_fullscreenMode)
	{
		tmpWindow = glfwCreateWindow(_monitor.getScrResWidth(), _monitor.getSrcResHeight(), gcnfg::TITLE,
			_monitor.getGLFWmonitorHandle(), _glfwWindow);
		_fullscreenMode = true;
	}
	else
	{
		tmpWindow = glfwCreateWindow(_monitor.getScrResWidth(), _monitor.getSrcResHeight(), gcnfg::TITLE,
			nullptr, _glfwWindow);
		_fullscreenMode = false;
	}
	// Destroy the current window
	glfwDestroyWindow(_glfwWindow);
	// Set _glfwWindow to the tmpWindow!
	_glfwWindow = tmpWindow;
	glfwMakeContextCurrent(_glfwWindow);
	glfwSetWindowUserPointer(_glfwWindow, this);

	setAllKeyCallbacks();
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
}

void Window::setAllKeyCallbacks()
{
	glfwSetKeyCallback(_glfwWindow, Window::key_callback);
	glfwSetMouseButtonCallback(_glfwWindow, Window::mouse_btn_callback);
	glfwSetCursorPosCallback(_glfwWindow, Window::cursor_pos_callback);
	glfwSetMonitorCallback(Window::monitor_callback);
}

void Window::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	// Always GET the current window
	Window * currentWindow = (Window*)glfwGetWindowUserPointer(window);
	// Perform whatever operations needed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key == GLFW_KEY_F11 && action == GLFW_PRESS)
	{
		currentWindow->toggleFullScreenMode();
	}
}

void Window::mouse_btn_callback(GLFWwindow * window, int button, int action, int mods)
{
	// Always GET the current window
	Window * currentWindow = (Window*)glfwGetWindowUserPointer(window);
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		std::cout << "Left Mouse button clicked at: (" << x << ", " << y << ")" << std::endl;
	}
}

void Window::cursor_pos_callback(GLFWwindow * window, double xpos, double ypos)
{
	//TODO...
}

void Window::monitor_callback(GLFWmonitor * monitor, int event)
{
	//TODO...
}