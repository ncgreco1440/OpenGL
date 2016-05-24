#include <Layers/Layer.h>

namespace graphics
{
    Layer::Layer(Renderer2D* renderer, Shader* shader, appm::mat4 projection):
        m_Renderer(renderer), m_Shader(shader), m_Projection(projection)
    {
        m_Shader->enable();
        m_Shader->setUniform("pr_matrix", m_Projection);
        m_Shader->disable();
    }

    Layer::~Layer()
    {
        delete m_Shader;
        delete m_Renderer;
        for(Renderable2D* x : m_RenderableObjects)
            delete x;
    }

    void Layer::add(Renderable2D* renderable)
    {
        m_RenderableObjects.push_back(renderable);
    }
    
    void Layer::render()
    {
        m_Shader->enable();
        
        for(Renderable2D* x : m_RenderableObjects)
            m_Renderer->submit(x);
        
        m_Renderer->flush();
        m_Shader->disable();
    }

}