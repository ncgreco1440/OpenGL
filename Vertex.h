#ifndef Vertex_h
#define Vertex_h

#include <GL/glew.h>

struct Position         // 12 bytes
{
    float x;
    float y;
    float z;
};

struct Color            // 4 bytes
{
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
};

/*!
 * Make sure that the size of vertex
 * in bytes is a multiple of 4! 
 * Reason is Matix Multiplication???
 */
struct Vertex          // 16 bytes
{
     Position position;
     Color color;
};

#endif
