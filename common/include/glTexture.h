#ifndef GLTEXTURE_H_
#define GLTEXTURE_H_

#include <GL/glew.h>

struct GLTexture
{
    GLuint id;
    unsigned long width;
    unsigned long height;
};

#endif