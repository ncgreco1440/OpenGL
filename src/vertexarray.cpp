#include <buffers/vertexarray.h>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &_arrayID);
}

VertexArray::~VertexArray()
{
    for(Buffer *x : _buffers)
        delete x;
}

void VertexArray::addBuffer(Buffer *buffer, GLuint index)
{
    this->bind();
    buffer->bind();
    
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
    
    this->unbind();
    buffer->unbind();
}

void VertexArray::bind() const
{
    glBindVertexArray(_arrayID);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}