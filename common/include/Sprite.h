#ifndef Sprite_h
#define Sprite_h

#include <GL/glew.h>
#include <iostream>
#include <string>
#include "Vertex.h"
#include "glTexture.h"
#include "ResourceManager.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();
    
    void init(float x, float y, float z, float width, float height, std::string texturePath);
    void draw();
    GLuint showText() { return _texture.id; };
private:
    float _x;               // x coordinate
    float _y;               // y coordinate
    float _z;               // z coordinate
    float _width;
    float _height;
    GLuint _vboID, _vaoID;
    GLTexture _texture;
};

#endif