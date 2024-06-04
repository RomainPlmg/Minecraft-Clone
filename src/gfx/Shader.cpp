#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include "OpenGL.h"
#include "Shader.h"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath): m_RendererID(0) {
    std::string vertexSource = ParseFile(vertexPath);
    std::string fragmentSource = ParseFile(fragmentPath);
    m_RendererID = CreateShader(vertexSource, fragmentSource);
}

Shader::~Shader() {
    GLCall(glDeleteProgram(m_RendererID));
}

std::string Shader::ParseFile(const std::string& filePath) {
    std::ifstream stream(filePath);

    std::string line;
    std::stringstream ss;
    while (getline(stream, line)) {
        ss << line << '\n';
    }
    return ss.str();
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // Print compile errors if any
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (!result) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];
        glGetShaderInfoLog(id, length, NULL, message);
        std::cout << "ERROR::SHADER::" << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void Shader::Bind() const {
    glUseProgram(m_RendererID);
}

void Shader::Unbind() const {
    glUseProgram(0);
}

void Shader::SetUniformBool(const std::string& name, bool value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        std::cerr << "Error: Unable to find the uniform \'" << name << "\'" << std::endl;
    }
    glUniform1i(uniformLoc, (int)value);
}

void Shader::SetUniformInt(const std::string& name, int value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        std::cerr << "Error: Unable to find the uniform \'" << name << "\'" << std::endl;
    }
    glUniform1i(uniformLoc, value);
}

void Shader::SetUniformFloat(const std::string& name, float value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        std::cerr << "Error: Unable to find the uniform \'" << name << "\'" << std::endl;
    }
    glUniform1f(uniformLoc, value);
}

void Shader::SetUniformVec2fv(const std::string& name, glm::vec2 value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        std::cerr << "Error: Unable to find the uniform \'" << name << "\'" << std::endl;
    }
    glUniform2fv(uniformLoc, 1, glm::value_ptr(value));
}

void Shader::SetUniformMat4fv(const std::string& name, glm::mat4 value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        std::cerr << "Error: Unable to find the uniform \'" << name << "\'" << std::endl;
    }
    glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(value));
}