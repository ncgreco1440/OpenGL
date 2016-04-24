#ifndef Sprite_h
#define Sprite_h

#include <GL/glew.h>
#include <iostream>

class Sprite
{
public:
    Sprite();
    ~Sprite();
    
    void init(float xCoord, float yCoord, float width, float height);
    void draw();
private:
    int _x;
    int _y;
    int _width;
    int _height;
    GLuint _vboID, _vaoID;
};

#endif