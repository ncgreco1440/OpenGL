#ifndef Sprite_h
#define Sprite_h

#include <GL/glew.h>
#include <iostream>
#include "Vertex.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();
    
    void init(float x, float y, float width, float height);
    void draw();
private:
    float _x;
    float _y;
    float _width;
    float _height;
    GLuint _vboID, _vaoID;
};

#endif