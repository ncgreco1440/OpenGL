#ifndef glslprogram_h
#define glslprogram_h

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <iostream>

class GLSLProgram
{
public:
    enum ShaderType
    {
        VERTEX,
        FRAGMENT,
        TESSILATION,
        GEOMETRY,
        PROGRAM
    };
    GLSLProgram():_programID(0), _vertexID(0), _fragmentID(0){};
    ~GLSLProgram();
    
    void compileShaders(const std::string& vertex, const std::string& fragment);
    void linkShaders();
    GLuint getUniformLocation(const std::string& uniformName);
    void use();
    void unuse();
private:
    GLuint _programID;
    GLuint _vertexID;
    GLuint _fragmentID;
    
    std::string readShaderFile(const std::string& file);
    void compileShader(const std::string& filepath, GLuint id, ShaderType type);
    void checkCompileErrors(GLuint, ShaderType);
    void printShaderType(ShaderType);
};

#endif
