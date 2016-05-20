#include <Sprite.h>

Sprite::Sprite(float x, float y, float width, float height, const appm::vec4& color)
    :Renderable2D(appm::vec3(x, y, 0), appm::vec2(width, height), color)
{}
