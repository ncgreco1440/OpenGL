#include <buffers/indexbuffer.h>

IndexBuffer::IndexBuffer(GLushort* data, GLsizei count):_count(count)
{
    glGenBuffers(1, &_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(GLuint* data, GLsizei count)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &_bufferID);
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}