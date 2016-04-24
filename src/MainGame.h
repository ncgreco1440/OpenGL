#ifndef MainGame_hpp
#define MainGame_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>
#include "Gameconfig.h"
#include "Sprite.h"
#include "shaderprog.h"

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
    MainGame();
    ~MainGame();
    
    void run();
private:
    void initSystems();
    void setWindowHints();
    void update();
    
    GLFWwindow * _window;
    const char * _title;
    GLuint _height, _width;
    GameState _gameState;
    
    Sprite _sprite;
    ShaderProg _shaders;
};

#endif