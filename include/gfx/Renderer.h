#pragma once

#include <glad/glad.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer {
public:
	Renderer();
	void Clear(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f) const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};