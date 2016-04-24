#include "MainGame.h"

/**********************************************************!
 * PUBLIC METHODS
 **********************************************************/
MainGame::MainGame():_window(0), _title(gconf::TITLE), _height(gconf::HEIGHT), _width(gconf::WIDTH), _gameState(GameState::PLAY)
{
    //...
}

MainGame::~MainGame()
{
    glfwTerminate();
}

void MainGame::run()
{
    try {
        initSystems();
        _sprite.init(-1.0, -1.0, 1.0, 1.0);
        _shaders.loadShaders("shader.vert", "shader.frag");
        std::cout << "Application running, using OpenGL version: "
            << glGetString(GL_SHADING_LANGUAGE_VERSION) << "..." << std::endl;
    } catch (const char * error) {
        std::cerr << error << std::endl;
        exit(EXIT_FAILURE);
    }
    update();
    std::cout << "Application ended by the user. \n"
        << "Goodbye!" << std::endl;
}

/**********************************************************!
 * PRIVATE METHODS
 **********************************************************/
void MainGame::initSystems()
{
    // STEP 1
    if(!glfwInit())
        throw "ERROR ON [MainGame.initSystems Step 1] GLFW Initialization Failed! Program Terminated!";
    setWindowHints();
    
    // STEP 2
    _window = glfwCreateWindow(_width, _height, _title, 0, 0);
    if(_window == NULL)
    {
        glfwTerminate();
        throw "ERROR ON [MainGame.initSystems Step 2] GLFW Window Creation Failed! Program Terminated!";
    }
    
    // STEP 3
    glfwMakeContextCurrent(_window);
    glfwSetKeyCallback(_window, gconf::key_callback);
    glfwSetMouseButtonCallback(_window, gconf::mouse_callback);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw "ERROR ON [MainGame.initSystems Step 3] GLEW Initialization Failed! Program Terminated!";
    }
    
    // STEP 4, by this step everything has succeeded, set the initial color of the screen
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
}

void MainGame::setWindowHints()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void MainGame::update()
{
    GLfloat triVertices[] = {
        // Triangle 1
        -1.0, -1.0,
        -1.0, 0.0,
        0.0, 0.0,
        
        // Triangle 2
        -1.0, -1.0,
        0.0, -1.0,
        0.0, 0.0

    };
    
    // Vertex Buffers
    GLuint vbo, vao;
    glGenBuffers(1, &vbo);
    glGenVertexArrays(1, &vao);
    
    // Vertex Arrays
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triVertices), triVertices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, (GLvoid*)0);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    while(!glfwWindowShouldClose(_window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        
        //Do game loop business...
        _shaders.use();
        _sprite.draw();

        glfwSwapBuffers(_window);
    }
}