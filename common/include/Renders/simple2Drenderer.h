#ifndef SIMPLE_2D_RENDERER_H_
#define SIMPLE_2D_RENDERER_H_

#include <Renders/renderer2D.h>
#include <deque>

class Simple2DRenderer : Renderer2D
{
public:
    void submit(const Renderable2D* renderable) override;
    void flush() override;
private:
    std::deque<const Renderable2D*> _renderQueue;
};


#endif