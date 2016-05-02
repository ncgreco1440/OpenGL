#include <Sprite.h>
#include "ImageLoader.h"

Sprite::Sprite() {};
Sprite::~Sprite()
{
    if(_vboID != 0)
    {
        glDeleteBuffers(1, &_vboID);
        glDeleteVertexArrays(1, &_vaoID);
    }
    std::cout << "deleted vbo" << std::endl;
};

void Sprite::init(float x, float y, float z, float width, float height, std::string texturePath)
{
    _x = x;
    _y = y;
    _z = z;
    _width = width;
    _height = height;
    //_texture = ResourceManager::getTexture(texturePath);
    _texture = ImageLoader::loadImage(texturePath);
    
    if(_vboID == 0)
    {
        glGenBuffers(1, &_vboID);
        glGenVertexArrays(1, &_vaoID);
    }
    
    Vertex vertexData[6];
    // First Triangle
    vertexData[0].setPosition(x + width, y + height, z);
    vertexData[0].setUV(1.0f, 1.0f);
    
    vertexData[1].setPosition(x, y + height, z);
    vertexData[1].setUV(0.0f, 1.0f);
    
    vertexData[2].setPosition(x, y, z);
    vertexData[2].setUV(0.0f, 0.0f);
    
    // Second Triangle
    vertexData[3].setPosition(x, y, z);
    vertexData[3].setUV(0.0f, 0.0f);
    
    vertexData[4].setPosition(x + width, y, z);
    vertexData[4].setUV(1.0f, 0.0f);
    
    vertexData[5].setPosition(x + width, y + height, z);
    vertexData[5].setUV(1.0f, 1.0f);
    
    for(int i = 0; i < 6; i++)
        vertexData[i].setColor(255, 0, 255);
    
    vertexData[1].setColor(0, 0, 255);
    vertexData[4].setColor(0, 255, 0);
    
    // Vertex Arrays
    glBindVertexArray(_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    // Unbind Everthing
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::draw()
{
    //glBindTexture(GL_TEXTURE_2D, _texture.id);

    // Bind the vertex Array
    glBindVertexArray(_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    // Enable the setting of attributes
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (GLvoid*)(sizeof(Vertex::position)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vertex::position) + sizeof(Vertex::color)));
    
    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    // Unbind VAO and VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
