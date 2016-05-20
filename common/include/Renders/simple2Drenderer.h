#ifndef SIMPLE_2D_RENDERER_H_
#define SIMPLE_2D_RENDERER_H_

#include <Renders/renderer2D.h>
#include <deque>
#include <StaticSprite.h>

class Simple2DRenderer : Renderer2D
{
public:
    void submit(const Renderable2D* renderable) override;
    void flush() override;
private:
    std::deque<const StaticSprite*> _renderQueue;
};


#endif