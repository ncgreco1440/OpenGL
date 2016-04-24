#include "Sprite.h"

Sprite::Sprite(){};
Sprite::~Sprite()
{
    if(_vboID != 0)
    {
        glDeleteBuffers(1, &_vboID);
        glDeleteVertexArrays(1, &_vaoID);
    }
};

void Sprite::init(float xCoord, float yCoord, float width, float height)
{
    _x = xCoord;
    _y = yCoord;
    _width = width;
    _height = height;
    
    if(_vboID == 0)
    {
        glGenBuffers(1, &_vboID);
        glGenVertexArrays(1, &_vaoID);
    }
    
    float vertexData[12] =
    {
        // First Triangle
        xCoord + width, yCoord + height,
        xCoord, yCoord + height,
        xCoord, yCoord,
        
        // Second Triangle
        xCoord, yCoord,
        xCoord + width, yCoord,
        xCoord + width, yCoord + height
    };

    glBindVertexArray(_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::draw()
{
    // Bind the vertex Array
    glBindVertexArray(_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    // Enable the setting of attributes
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    // Disable the attributes
    glDisableVertexAttribArray(0);
    
    // Unbind VAO and VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
