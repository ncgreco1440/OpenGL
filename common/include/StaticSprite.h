#ifndef STATIC_SPRITE_H_
#define STATIC_SPRITE_H_

#include <Renders/renderable2D.h>

class StaticSprite : public Renderable2D
{
private:
    VertexArray* _vertexArray;
    IndexBuffer* _indexBuffer;
    Shader& _shader;
public:
    StaticSprite(float x, float y, float width, float height, const appm::vec4& color, Shader& shader);
    ~StaticSprite();
    
    const VertexArray* getVAO() const { return _vertexArray; };
    const IndexBuffer* getIBO() const { return _indexBuffer; };
    
    Shader& getShader() const { return _shader; };
};

#endif