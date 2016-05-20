#ifndef RENDERER_2D_H_
#define RENDERER_2D_H_

#include <GL/glew.h>
#include <Renders/renderable2D.h>
#include <appm/appm.h>

class Renderer2D
{
public:
    //virtual ~Renderer2D() {};
    virtual void submit(const Renderable2D* renderable) = 0;
    virtual void flush() = 0;
};

#endif