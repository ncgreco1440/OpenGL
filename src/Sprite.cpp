#include <Sprite.h>

Sprite::Sprite() {};
Sprite::~Sprite()
{
    if(_vboID != 0)
    {
        glDeleteBuffers(1, &_vboID);
        glDeleteVertexArrays(1, &_vaoID);
    }
};

void Sprite::init(float x, float y, float width, float height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    
    if(_vboID == 0)
    {
        glGenBuffers(1, &_vboID);
        glGenVertexArrays(1, &_vaoID);
    }
    
    Vertex vertexData[6];
    // First Triangle
    vertexData[0].position.x = x + width;
    vertexData[0].position.y = y + height;
    vertexData[0].position.z = 0.0f;
    
    vertexData[1].position.x = x;
    vertexData[1].position.y = y + height;
    vertexData[1].position.z = 0.0f;
    
    vertexData[2].position.x = x;
    vertexData[2].position.y = y;
    vertexData[2].position.z = 0.0f;
    
    // Second Triangle
    vertexData[3].position.x = x;
    vertexData[3].position.y = y;
    vertexData[3].position.z = 0.0f;
    
    vertexData[4].position.x = x + width;
    vertexData[4].position.y = y;
    vertexData[4].position.z = 0.0f;
    
    vertexData[5].position.x = x + width;
    vertexData[5].position.y = y + height;
    vertexData[5].position.z = 0.0f;
    
    for(int i = 0; i < 6; i++)
    {
        vertexData[i].color.r = 255;
        vertexData[i].color.g = 0;
        vertexData[i].color.b = 255;
        vertexData[i].color.a = 255;

    }
    
    vertexData[1].color.r = 0;
    vertexData[1].color.g = 0;
    vertexData[1].color.b = 255;
    vertexData[1].color.a = 255;
    
    vertexData[4].color.r = 0;
    vertexData[4].color.g = 255;
    vertexData[4].color.b = 0;
    vertexData[4].color.a = 255;

    
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
    // Bind the vertex Array
    glBindVertexArray(_vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    // Enable the setting of attributes
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (GLvoid*)(sizeof(Vertex::position)));
    
    // Draw
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    // Unbind VAO and VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
