#pragma once

#include "Cube.h"
#include "Sprite.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer {
public:
    Renderer();
    void Clear(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f) const;
    void Draw(VertexArray& va, IndexBuffer& ib, const Shader& shader) const;
};