#pragma once

#include "OpenGL.h"
#include <string>

struct ShaderProgramSource {
	std::string vertexSource;
	std::string fragmentSource;
};

class Shader {
private:
	unsigned int m_RendererID; // The program ID
	std::string m_FilePath;
	std::string ParseFile(const std::string& filePath);
    unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath); // Constructor
	~Shader();

	void Bind() const;
	void Unbind() const;

	/* Utility uniform functions */
	void SetUniformBool(const std::string& name, bool value) const;
	void SetUniformInt(const std::string& name, int value) const;
	void SetUniformFloat(const std::string& name, float value) const;
	void SetUniformVec2fv(const std::string& name, glm::vec2 value) const;
	void SetUniformMat4fv(const std::string& name, glm::mat4 value) const;
};