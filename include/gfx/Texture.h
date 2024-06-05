#pragma once

#include "OpenGL.h"

class Texture {
private:
	unsigned int m_RendererID;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture();
	~Texture();

	int LoadFromFile(const std::string& path);
	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline glm::vec2 GetSize() const { return glm::vec2(m_Width, m_Height); }
};