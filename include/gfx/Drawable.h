#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include <vector>

enum DrawableType {
    CUBE,
    SPRITE
};

class Drawable {
protected:
    DrawableType m_Type;
    VertexArray *m_Va;
    VertexBuffer *m_Vb;
    VertexBufferLayout *m_Layout;
    IndexBuffer *m_Ib;
    Texture *m_Texture;

    std::vector<GLuint> m_Indices;
public:
    /* Virtual destructor */
    virtual ~Drawable() = default;

    /* Methods */
    void Bind() const;

    /* Setters */
    inline void SetTexture(const std::string &texturePath) { m_Texture->LoadFromFile(texturePath); }

    /* Getters */
    virtual int GetType() const = 0;
    inline VertexArray &GetVertexArray() { return *m_Va; }
    inline IndexBuffer &GetIndexBuffer() { return *m_Ib; }
    inline Texture &GetTexture() const { return *m_Texture; }
};
