#include <shaderprog.h>
#include <fstream>
#include <iostream>
#include <sstream>

ShaderProg::ShaderProg():mHandle(0){}

ShaderProg::~ShaderProg()
{
    glDeleteProgram(mHandle);
}

bool ShaderProg::loadShaders(const char * vertShader, const char * fragShader)
{
    string vsStr = fileToString(vertShader);
    string fsStr = fileToString(fragShader);
    const GLchar * vsStrPtr = vsStr.c_str();
    const GLchar * fsStrPtr = fsStr.c_str();
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    // Compile Shaders
    glShaderSource(vertexShader, 1, &vsStrPtr, nullptr);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, VERTEX);
    glShaderSource(fragmentShader, 1, &fsStrPtr, nullptr);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, FRAGMENT);
    
    // Create Shader Program
    mHandle = glCreateProgram();
    
    glAttachShader(mHandle, vertexShader);
    glAttachShader(mHandle, fragmentShader);
    glLinkProgram(mHandle);
    checkCompileErrors(mHandle, PROGRAM);
    
    // After shaders are linked, delete them to free up the memory
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    mUniformLocation.clear();
    
    return true;
}

void ShaderProg::use()
{
    if(mHandle > 0)
        glUseProgram(mHandle);
}

string ShaderProg::fileToString(const string& filename)
{
    std::stringstream ss;
    std::ifstream file;
    
    try
    {
        file.open(filename, std::ios::in);
        if(!file.fail())
        {
            ss << file.rdbuf();
        }
        file.close();
    }
    catch (std::exception ex)
    {
        std::cerr << "ERROR: cannot open open/read shader file \"" << filename << "\"" << std::endl;
    }
    
    return ss.str();
}

void ShaderProg::checkCompileErrors(GLuint shader, ShaderType type)
{
    int status = 0;
    if(type == PROGRAM)
    {
        glGetProgramiv(mHandle, GL_LINK_STATUS, &status);
        if(status == GL_FALSE)
        {
            GLint length = 0;
            glGetProgramiv(mHandle, GL_INFO_LOG_LENGTH, &length);
            string errorLog(length, ' ');
            glGetProgramInfoLog(mHandle, length, &length, &errorLog[0]);
            std::cerr << "ERROR: Shader Program failed to link! " << errorLog << std::endl;
        }
    }
    else    // VERTEX or FRAGMENT
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if(status == GL_FALSE)
        {
            GLint length = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
            string errorLog(length, ' ');
            glGetShaderInfoLog(shader, length, &length, &errorLog[0]);
            std::cerr << "ERROR: " << (type == VERTEX ? "Vertex" : "Fragment") << " Shader failed to compile! " << errorLog << std::endl;
        }
    }
}

GLint ShaderProg::getUniformLocation(const GLchar * name)
{
    std::map<string, GLint>::iterator it = mUniformLocation.find(name);
    if(it == mUniformLocation.end())
    {
        mUniformLocation[name] = glGetUniformLocation(mHandle, name);
    }
    return mUniformLocation[name];
}

void ShaderProg::setUniform(const GLchar * name, const glm::vec2& v)
{
    GLint loc = getUniformLocation(name);
    glUniform2f(loc, v.x, v.y);
}

void ShaderProg::setUniform(const GLchar * name, const glm::vec3& v)
{
    GLint loc = getUniformLocation(name);
    glUniform3f(loc, v.x, v.y, v.z);
}

void ShaderProg::setUniform(const GLchar * name, const glm::vec4& v)
{
    GLint loc = getUniformLocation(name);
    glUniform4f(loc, v.x, v.y, v.z, v.w);
}

GLuint ShaderProg::reference()
{
    return mHandle;
}

