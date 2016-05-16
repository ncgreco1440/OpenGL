#include <GameConfig/Window.h>
#include <GameConfig/config.h>
#include <GameConfig/Input.h>

Window::Window():_glfwWindow(0), _title(gcnfg::TITLE)
{
	// Initialize GLFW
	initGLFW();
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

GLFWwindow * Window::getGLFWwindowHandle() const
{
	return _glfwWindow;
}

void Window::displayGraphicalInfo() const
{
    cout << "=================== Graphical Info =======================\n"
        << "GPU Vendor: " << glGetString(GL_VENDOR) << "\n"
        << "GPU: " << glGetString(GL_RENDERER) << "\n"
        << "OpenGL Version: " << glGetString(GL_VERSION) << "\n"
        << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

void Window::initGLFW()
{
	// Step 1) Initialize GLFW else, fatal_error
	if (!glfwInit())
		gcnfg::fatal_error(-1, "GLFW Initialization has failed, Program Terminated with exit code -1");
    
    // Step 2) Set up window hints and error callbacks
    setWindowHints();
	//glfwSetErrorCallback(gcnfg::fatal_error);

	// Step 3) Initialize the Monitor
	_monitor.initMonitor();

	// Step 4) Create the GLFW Window
	/*_glfwWindow = glfwCreateWindow(_monitor.getScrResWidth(), _monitor.getSrcResHeight(), 
		_title, _monitor.getGLFWmonitorHandle(), nullptr);*/
   _glfwWindow = glfwCreateWindow(960, 540,
        _title, nullptr, nullptr);


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
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void Window::toggleFullScreenMode()
{
	GLFWwindow * tmpWindow;
	// Create a temp window
	if (!_fullscreenMode)
	{
        // Go fullscreen mode
		tmpWindow = glfwCreateWindow(_monitor.getScrResWidth(), _monitor.getSrcResHeight(), gcnfg::TITLE,
			_monitor.getGLFWmonitorHandle(), _glfwWindow);
		_fullscreenMode = true;
	}
	else
	{
        // Go windowed mode
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
	glfwSetKeyCallback(_glfwWindow, Input::key_callback);
	glfwSetMouseButtonCallback(_glfwWindow, Input::mouse_btn_callback);
	glfwSetCursorPosCallback(_glfwWindow, Input::cursor_pos_callback);
}