#ifndef RENDER_H_
#define RENDER_H_

#include <Renders/renderer2d.h>
//#include <buffers/vertexarray.h>
#include <buffers/indexbuffer.h>

#define RENDERER_MAX_SPRITES        10000
#define RENDERER_VERTEX_SIZE        sizeof(VertexData)
#define RENDERER_SPRITE_SIZE        RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE        RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE       RENDERER_MAX_SPRITES * 6
#define SHADER_VERTEX_INDEX         0
#define SHADER_COLOR_INDEX          1

class Render : public Renderer2D
{
private:
    //VertexArray m_VAO;
    IndexBuffer* m_IBO;
    GLuint m_VBO;
    GLuint m_VAO;
    VertexData* m_Buffer;
    int m_IndexCount = 0;
    
    void init();
public:
    Render();
    ~Render();
    void begin();
    void submit(const Renderable2D* renderable) override;
    void end();
    void flush() override;
};

#endif