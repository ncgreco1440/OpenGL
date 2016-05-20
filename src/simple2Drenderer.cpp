#include <Renders/simple2Drenderer.h>


void Simple2DRenderer::submit(const Renderable2D* renderable)
{
    _renderQueue.push_back((StaticSprite*)renderable);
}

void Simple2DRenderer::flush()
{
    while(!_renderQueue.empty())
    {
        const StaticSprite* sprite = _renderQueue.front();
        sprite->getVAO()->bind();
        sprite->getIBO()->bind();
        
        sprite->getShader().setUniform("ml_matrix", appm::mat4::translation(sprite->getPosition()));
        glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);
        
        sprite->getIBO()->unbind();
        sprite->getVAO()->unbind();
        
        _renderQueue.pop_front();
    }
}
