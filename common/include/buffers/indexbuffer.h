#ifndef INDEXBUFFER_H_
#define INDEXBUFFER_H_

#include <GL/glew.h>

class IndexBuffer
{
public:
    IndexBuffer(GLushort* data, GLsizei count);
    ~IndexBuffer();
    
    GLuint getCount() const { return _count; };
    void bind() const;
    void unbind() const;
private:
    GLuint _bufferID;
    GLuint _count;
};


#endif