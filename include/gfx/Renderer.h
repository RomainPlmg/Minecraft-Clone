#pragma once

#include "Cube.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer {
private:
    Shader *m_Shader;
public:
    Renderer(GLenum mode = GL_FILL);
    void Clear(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f) const;
    void Draw(Cube& cube) const;

    /* Getters */
    inline Shader &GetShader() const { return *m_Shader; }
};