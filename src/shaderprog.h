#ifndef SHADERPROG_H_
#define SHADERPROG_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <map>
#include <string>
using std::string;

class ShaderProg
{
public:
    enum ShaderType
    {
        VERTEX,
        FRAGMENT,
        PROGRAM
    };
    ShaderProg();
    ~ShaderProg();
    bool loadShaders(const char *, const char *);
    void use();
    void setUniform(const GLchar *, const glm::vec2& v);
    void setUniform(const GLchar *, const glm::vec3& v);
    void setUniform(const GLchar *, const glm::vec4& v);
    GLuint reference();
private:
    string fileToString(const string&);
    void checkCompileErrors(GLuint, ShaderType);
    GLint getUniformLocation(const GLchar *);
    
    GLuint mHandle;
    std::map<string, GLint> mUniformLocation;
};

#endif
