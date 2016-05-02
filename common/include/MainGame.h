#ifndef MainGame_hpp
#define MainGame_hpp

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>
#include <vector>
#include "Gameconfig.h"
#include "Sprite.h"
#include "shaderprog.h"
#include "glslprogram.h"
#include "RandomGen.h"

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
    MainGame();
    ~MainGame();
    
    void run();
private:
    void initSystems();
    void initShaders();
    void setWindowHints();
    void update();
    
    GLFWwindow * _window;
    const char * _title;
    GLuint _height, _width;
    GameState _gameState;
    GLSLProgram _colorProgram;
    float _time;
    
    //std::vector <Sprite*> _sprites;
    //Sprite _spriteArray[1];
    
    Sprite _s1;
    Sprite _s2;
    Sprite _s3;
};

#endif