#ifndef RENDERABLE_2D_H_
#define RENDERABLE_2D_H_

#include <GL/glew.h>
#include <buffers/buffer.h>
#include <buffers/indexbuffer.h>
#include <buffers/vertexarray.h>
#include <utils/Shader.h>

#include <appm/appm.h>

struct VertexData                   // Size MUST be a multiple of 4 due to padding
{
    appm::vec3 vertex;              // 12 bytes +
    //appm::vec4 color;               // 16 bytes +
	unsigned int color;				// 4 bytes +
};                                  // 16 bytes =

class Renderable2D
{
private:
// Protected Data Members
    appm::vec3 _position;
    appm::vec2 _size;
    appm::vec4 _color;
    
public:
// Constructor
    Renderable2D(appm::vec3 position, appm::vec2 size, appm::vec4 color)
        :_position(position), _size(size), _color(color){}
    
    ~Renderable2D(){}
    
    const appm::vec3& getPosition() const { return _position; };
    const appm::vec2& getSize() const { return _size; };
    const appm::vec4& getColor() const { return _color; };
};

#endif