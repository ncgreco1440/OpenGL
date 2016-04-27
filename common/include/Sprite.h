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
    
    void init(float x, float y, float z, float width, float height);
    void draw();
private:
    float _x;               // x coordinate
    float _y;               // y coordinate
    float _z;               // z coordinate
    float _width;
    float _height;
    GLuint _vboID, _vaoID;
};

#endif