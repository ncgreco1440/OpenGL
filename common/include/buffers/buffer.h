#ifndef BUFFER_H_
#define BUFFER_H_

#include <GL/glew.h>

class Buffer
{
public:
    Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
    ~Buffer() { glDeleteBuffers(1, &_bufferID); };
    
    GLuint getComponentCount() const { return _componentCount; };
    void bind() const;
    void unbind() const;
private:
    GLuint _bufferID;
    GLuint _componentCount;             // Tells the VBO how the data should be counted
};

#endif