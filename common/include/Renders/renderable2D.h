#ifndef RENDERABLE_2D_H_
#define RENDERABLE_2D_H_

#include <GL/glew.h>
#include <buffers/buffer.h>
#include <buffers/indexbuffer.h>
#include <buffers/vertexarray.h>
#include <utils/Shader.h>

#include <appm/appm.h>

class Renderable2D
{
private:
// Protected Data Members
    appm::vec3 _position;
    appm::vec2 _size;
    appm::vec4 _color;
    
    VertexArray* _vertexArray;
    IndexBuffer* _indexBuffer;
    Shader& _shader;
    
public:
// Constructor
    Renderable2D(appm::vec3 position, appm::vec2 size, appm::vec4 color, Shader& shader)
        :_position(position), _size(size), _color(color), _shader(shader)
    {
        _vertexArray = new VertexArray();
        GLfloat vertices[] =
        {
            0, 0, 0,
            0, size.y, 0,
            size.x, size.y, 0,
            size.x, 0, 0
        };
        
        GLfloat colors[] =
        {
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w,
            color.x, color.y, color.z, color.w
        };
        
        _vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
        _vertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
        
        GLushort indices[] = {0,1,2,2,3,0};
        _indexBuffer = new IndexBuffer(indices, 6);
    }
    
    ~Renderable2D()
    {
        delete _vertexArray;
        delete _indexBuffer;
    }

    const VertexArray* getVAO() const { return _vertexArray; };
    const IndexBuffer* getIBO() const { return _indexBuffer; };
    
    Shader& getShader() const { return _shader; };
    
    const appm::vec3& getPosition() const { return _position; };
    const appm::vec2& getSize() const { return _size; };
    const appm::vec4& getColor() const { return _color; };
};

#endif