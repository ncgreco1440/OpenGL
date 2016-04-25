#include <glslprogram.h>

/**********************************************************!
 * PUBLIC METHODS
 **********************************************************/
GLSLProgram::~GLSLProgram()
{
    glDeleteProgram(_programID);
}

void GLSLProgram::compileShaders(const std::string &vertex, const std::string &fragment)
{
    _programID = glCreateProgram();
    _vertexID = glCreateShader(GL_VERTEX_SHADER);
    _fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    
    compileShader(vertex, _vertexID, VERTEX);
    compileShader(fragment, _fragmentID, FRAGMENT);
}

void GLSLProgram::linkShaders()
{
    glAttachShader(_programID, _vertexID);
    glAttachShader(_programID, _fragmentID);
    glLinkProgram(_programID);
    checkCompileErrors(_programID, PROGRAM);
    
    glDetachShader(_programID, _vertexID);
    glDetachShader(_programID, _fragmentID);
    glDeleteShader(_vertexID);
    glDeleteShader(_fragmentID);
}

GLuint GLSLProgram::getUniformLocation(const std::string& uniformName)
{
    GLint location = glGetUniformLocation(_programID, uniformName.c_str());
    if(location == GL_INVALID_INDEX)
    {
        std::cerr << "ERROR in [GLSLProgram.getUniformLocation] " + uniformName + " was not found!" << std::endl;
        exit(69);
    }
    return location;
}

void GLSLProgram::use()
{
    glUseProgram(_programID);
}

void GLSLProgram::unuse()
{
    glUseProgram(0);
}
/**********************************************************!
 * PRIVATE METHODS
 **********************************************************/
std::string GLSLProgram::readShaderFile(const std::string &file)
{
    std::ifstream File(file);
    if(File.fail())
        std::cerr << "ERROR: Failed to open shader file\"" << file << "\"" << std::endl;
    
    std::string fileContents = "";
    std::string line;
    while(std::getline(File, line))
    {
        fileContents += line + "\n";
    }
    
    File.close();
    
    return fileContents;
}

void GLSLProgram::compileShader(const std::string &filepath, GLuint id, ShaderType type)
{
    std::string shaderStr = readShaderFile(filepath);
    const GLchar * contents = shaderStr.c_str();
    glShaderSource(id, 1, &contents, nullptr);
    
    glCompileShader(id);
    checkCompileErrors(id, type);
}

void GLSLProgram::checkCompileErrors(GLuint shader, ShaderType type)
{
    int status = 0;
    if(type == PROGRAM)
    {
        glGetProgramiv(_programID, GL_LINK_STATUS, &status);
        if(status == GL_FALSE)
        {
            GLint length = 0;
            glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &length);
            std::string errorLog(length, ' ');
            glGetProgramInfoLog(_programID, length, &length, &errorLog[0]);
            std::cerr << "ERROR: Shader Program failed to link! " << errorLog << std::endl;
            glDeleteShader(_vertexID);
            glDeleteShader(_fragmentID);
        }
    }
    else    // VERTEX or FRAGMENT
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if(status == GL_FALSE)
        {
            GLint length = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
            std::string errorLog(length, ' ');
            glGetShaderInfoLog(shader, length, &length, &errorLog[0]);
            std::cerr << "ERROR: ";
            printShaderType(type);
            std::cerr << " Shader failed to compile! " << errorLog << std::endl;
            glDeleteShader(shader);
        }
    }
}

void GLSLProgram::printShaderType(ShaderType type)
{
    switch(type)
    {
        case VERTEX: {
            std::cerr << "VERTEX"; break;
        }
        case FRAGMENT: {
            std::cerr << "FRAGMENT"; break;
        }
        case TESSILATION: {
            std::cerr << "TESSILATION"; break;
        }
        case GEOMETRY: {
            std::cerr << "GEOMETRY"; break;
        }
    }
}