#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Shader.h"
#include "Transformable.h"
#include <string>

class Cube : public Transformable
{
private:
    void Init(const std::string &texturePath);

    VertexArray *m_Va;
    VertexBuffer *m_Vb;
    VertexBufferLayout *m_Layout;
    IndexBuffer *m_Ib;
    Texture *m_Texture;

public:
    Cube();
    Cube(const std::string &texturePath);

    /* Getters */
    inline VertexArray &GetVertexArray() const { return *m_Va; }
    inline IndexBuffer &GetIndexBuffer() const { return *m_Ib; }

    /* Setters */
    inline void SetTexture(const std::string &texturePath) { m_Texture->LoadFromFile(texturePath); }
};