#include <Render/Render.h>

Render::Render()
{
    init();
}

Render::~Render()
{
    delete m_IBO;
    glDeleteBuffers(1, &m_VBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void Render::init()
{
    glGenBuffers(1, &m_VBO);
    glGenVertexArrays(1, &m_VAO);
    
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, 0, GL_DYNAMIC_DRAW);
    // Vertex Attribute
    glVertexAttribPointer(SHADER_VERTEX_INDEX,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          RENDERER_VERTEX_SIZE,
                          (GLvoid*)0);
    // Color Attribute
    glVertexAttribPointer(SHADER_COLOR_INDEX,
                          4,
                          GL_UNSIGNED_BYTE,
                          GL_TRUE,
                          RENDERER_VERTEX_SIZE,
                          (GLvoid*)(sizeof(VertexData::vertex)));
    
    glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
    glEnableVertexAttribArray(SHADER_COLOR_INDEX);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    GLuint * indices = new GLuint[RENDERER_INDICES_SIZE];
    
    for(int i = 0, offset = 0; i < RENDERER_INDICES_SIZE; i+=6, offset+=4)
    {
        indices[i] = offset + 0;
        indices[i + 1] = offset + 1;
        indices[i + 2] = offset + 2;
        
        indices[i + 3] = offset + 2;
        indices[i + 4] = offset + 3;
        indices[i + 5] = offset + 0;
    }
    
    m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
	//delete[] indices;
    glBindVertexArray(0);
}

void Render::begin()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void Render::submit(const Renderable2D *renderable)
{
    const appm::vec3& position = renderable->getPosition();
    const appm::vec2& size = renderable->getSize();
    const appm::vec4& color = renderable->getColor();
	int r = color.r * 255.0f;
	int g = color.g * 255.0f;
	int b = color.b * 255.0f;
	int a = color.a * 255.0f;

	unsigned int c = a << 24 | b << 16 | g << 8 | r;
    
    m_Buffer->vertex = position;
    m_Buffer->color = c;
    m_Buffer++;
    
    m_Buffer->vertex = appm::vec3(position.x, position.y + size.y, position.z);
    m_Buffer->color = c;
    m_Buffer++;
    
    m_Buffer->vertex = appm::vec3(position.x + size.x, position.y + size.y, position.z);
    m_Buffer->color = c;
    m_Buffer++;
    
    m_Buffer->vertex = appm::vec3(position.x + size.x, position.y, position.z);
    m_Buffer->color = c;
    m_Buffer++;
    
    m_IndexCount += 6;
}

void Render::end()
{
    glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Render::flush()
{
    glBindVertexArray(m_VAO);
    m_IBO->bind();
    
    glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, 0);
    
    m_IBO->unbind();
    glBindVertexArray(0);
    m_IndexCount = 0;
}