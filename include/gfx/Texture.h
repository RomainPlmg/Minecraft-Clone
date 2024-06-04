#pragma once

#include "Renderer.h"
#include "Vector2.h"

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

	inline Vector2u GetSize() const { return Vector2u(m_Width, m_Height); }
};