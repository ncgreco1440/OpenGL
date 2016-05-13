#include <Renders/simple2Drenderer.h>


void Simple2DRenderer::submit(const Renderable2D* renderable)
{
    _renderQueue.push_back(renderable);
}

void Simple2DRenderer::flush()
{
    while(!_renderQueue.empty())
    {
        const Renderable2D* renderable = _renderQueue.front();
        renderable->getVAO()->bind();
        renderable->getIBO()->bind();
        
        renderable->getShader().setUniform("ml_matrix", appm::mat4::translation(renderable->getPosition()));
        glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);
        
        renderable->getIBO()->unbind();
        renderable->getVAO()->unbind();
        
        _renderQueue.pop_front();
    }
}
