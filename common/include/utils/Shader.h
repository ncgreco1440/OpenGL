#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <appm/appm.h>

class Shader
{
private:
    GLuint _progID;
    const char *_vertFile;
    const char *_fragFile;
    
    GLuint load();
    void compileShader(const char * filePath, GLuint shaderID);
    void chkCompileError(const char * filePath, GLuint shaderID);
    void chkLinkError(GLuint prog);
// Get Uniform
    GLint getUniformLocation(const GLchar* name);
public:
// Constructor/Destructor
    Shader(const char * vertFilePath, const char * fragFilePath);
    ~Shader();
// Public Interface
    void enable() const;
    void disable() const;
    GLuint getHandle() const { return _progID; };

// Set Uniforms
    void setUniform(const GLchar* name, const float value);
    void setUniform(const GLchar* name, const int value);
    void setUniform(const GLchar* name, const appm::mat4& matrix);
    void setUniform(const GLchar* name, const appm::vec2& vector);
    void setUniform(const GLchar* name, const appm::vec3& vector);
    void setUniform(const GLchar* name, const appm::vec4& vector);
};

#endif