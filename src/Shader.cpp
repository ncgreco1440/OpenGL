#include <utils/Shader.h>
#include <utils/fileio.h>
#include <iostream>
#include <Gameconfig/config.h>

Shader::Shader(const char * vertFilePath, const char * fragFilePath):_vertFile(vertFilePath), _fragFile(fragFilePath)
{
    _progID = load();
}

Shader::~Shader()
{
    std::cout << "Shader Deleted!" << std::endl;
    glDeleteProgram(_progID);
}

GLuint Shader::load()
{
    GLuint program = glCreateProgram();
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    
    compileShader(_vertFile, vertex);
    compileShader(_fragFile, fragment);
    
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glValidateProgram(program);
    chkLinkError(program);
    
    glDetachShader(program, vertex);
    glDetachShader(program, fragment);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    
    return program;
}

void Shader::compileShader(const char * file, GLuint shaderID)
{
    std::string source = utils::read_file(file);
    const char * src = source.c_str();

    glShaderSource(shaderID, 1, &src, nullptr);
    glCompileShader(shaderID);
    chkCompileError(file, shaderID);
}

void Shader::chkCompileError(const char *filePath, GLuint shaderID)
{
    int status = 0;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE)
    {
        GLint length = 0;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
        std::string errorLog(length, ' ');
        glGetShaderInfoLog(shaderID, length, &length, &errorLog[0]);
        std::cerr << "SHADER COMPILE ERROR: In file \"" << filePath << "\n";
        glDeleteShader(shaderID);
        gcnfg::fatal_error(-1, errorLog.c_str());
    }
}

void Shader::chkLinkError(GLuint prog)
{
    int status = 0;
    glGetProgramiv(prog, GL_LINK_STATUS, &status);
    if(status == GL_FALSE)
    {
        GLint length = 0;
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &length);
        std::string errorLog(length, ' ');
        glGetProgramInfoLog(prog, length, &length, &errorLog[0]);
        std::cerr << "SHADER LINK ERROR: Here's what went wrong...\n";
         gcnfg::fatal_error(-1, errorLog.c_str());
    }

}

void Shader::enable() const
{
    glUseProgram(_progID);
}

void Shader::disable() const
{
    glUseProgram(0);
}

GLint Shader::getUniformLocation(const GLchar* name)
{
    return glGetUniformLocation(_progID, name);
}

void Shader::setUniform(const GLchar* name, const float value)
{
    glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform(const GLchar* name, const int value)
{
    glUniform1i(getUniformLocation(name), value);
}

void Shader::setUniform(const GLchar* name, const appm::mat4& matrix)
{
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
}

void Shader::setUniform(const GLchar* name, const appm::vec2& vector)
{
    glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void Shader::setUniform(const GLchar* name, const appm::vec3& vector)
{
    glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}

void Shader::setUniform(const GLchar* name, const appm::vec4& vector)
{
    glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}