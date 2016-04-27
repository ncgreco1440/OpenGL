#ifndef Vertex_h
#define Vertex_h

#include <GL/glew.h>

/*
 * XYZ Geometry coordinates 
 * 12 Bytes
 */
struct Position
{
    float x;
    float y;
    float z;
};

/*
 * RGBA color values
 * 4 Bytes
 */
struct Color
{
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
};

/* 
 * UV Texture Coordinates
 * 8 Bytes
 */
struct UV
{
    float u;
    float v;
};

/**********************************************************!
 * IMPORTANT 
 * 
 * Make sure that the size of Vertex, in bytes, is a
 * multiple of 4!
 * Reason is Matix Multiplication??? I Think?...
 **********************************************************/
struct Vertex
{
/**********************************************************!
* DATA MEMBERS              24 Bytes
**********************************************************/
    Position position;
    Color color;
    UV uv;
/**********************************************************!
* HELPERS
**********************************************************/
    // setPosition: set the x, y, and z geometry coords. z is 0 by default
    void setPosition(float x, float y, float z = 0)
    {
        position.x = x;
        position.y = y;
        position.z = z;
    }
    
    // setColor: set the r, g, b, a color values. a is 255 by default
    void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a = 255)
    {
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }
    
    // setUV: set the uv map of the texture.
    void setUV(float u, float v)
    {
        uv.u = u;
        uv.v = v;
    }
};

#endif
