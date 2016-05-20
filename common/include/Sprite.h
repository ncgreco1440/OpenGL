#ifndef SPRITE_H_
#define SPRITE_H_

#include <Renders/renderable2D.h>

class Sprite : public Renderable2D
{
public:
    Sprite(float x, float y, float width, float height, const appm::vec4& color);
};

#endif