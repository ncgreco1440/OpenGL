#ifndef VERTEXARRAY_H_
#define VERTEXARRAY_H_

#include <GL/glew.h>
#include <buffers/buffer.h>
#include <vector>

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();
    
    void addBuffer(Buffer* buffer, GLuint index);
    void bind() const;
    void unbind() const;
private:
    GLuint _arrayID;
    std::vector<Buffer*> _buffers;
};


#endif