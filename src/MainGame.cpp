#include <MainGame.h>
#include "ImageLoader.h"

/**********************************************************!
 * PUBLIC METHODS
 **********************************************************/
MainGame::MainGame():_window(0), _title(gconf::TITLE), _height(gconf::HEIGHT), _width(gconf::WIDTH),
_gameState(GameState::PLAY), _time(0.0f){}

MainGame::~MainGame()
{
    glfwTerminate();
}

void MainGame::run()
{
    try {
        initSystems();
        _sprite.init(-1.0f, -1.0f, 0.0f, 2.0f, 2.0f);
        _playerTexture = ImageLoader::loadImage("Textures/PNG/CharacterRight_Standing.png");
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
    initShaders();
}

void MainGame::initShaders()
{
    _colorProgram.compileShaders("Shaders/shader.vert", "Shaders/shader.frag");
    _colorProgram.linkShaders();
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
    while(!glfwWindowShouldClose(_window))
    {
        _time += 0.04;
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        
        //Do game loop business...
        _colorProgram.use();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, _playerTexture.id);
        GLint textureLoc = _colorProgram.getUniformLocation("sampleTexture");
        glUniform1i(textureLoc, 0);
        
        GLuint timeLoc = _colorProgram.getUniformLocation("time");
        glUniform1f(timeLoc, _time);
        
        _sprite.draw();
        
        glBindTexture(GL_TEXTURE_2D, 0);
        _colorProgram.unuse();
        glfwSwapBuffers(_window);
    }
}