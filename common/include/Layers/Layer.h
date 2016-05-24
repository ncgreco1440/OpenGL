#ifndef LAYER_H_
#define LAYER_H_

#include <Renders/renderable2D.h>
#include <Renders/renderer2D.h>
#include <utils/Shader.h>
#include <appm/appm.h>

namespace graphics
{

    class Layer
    {
    protected:
        Layer(Renderer2D* renderer, Shader* shader, appm::mat4 projection);
        
        Renderer2D* m_Renderer;
        std::vector<Renderable2D*> m_RenderableObjects;
        Shader* m_Shader;
        appm::mat4 m_Projection;
    private:
    public:
        //Layer();
        virtual ~Layer();
        virtual void add(Renderable2D* renderable);
        virtual void render();
    };
}


#endif