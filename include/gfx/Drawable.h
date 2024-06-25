#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include <vector>

class Drawable {
protected:
    VertexBuffer *m_Vb;
    IndexBuffer *m_Ib;
    VertexBufferLayout *m_Layout;
    VertexArray *m_Va;

public:
    /* Constructor */
    Drawable();

    /* Virtual destructor */
    virtual ~Drawable();

    /* Methods */
    virtual void Draw(const Renderer &renderer) = 0;

    /* Getters */
    inline const VertexArray &GetVertexArray() const { return *m_Va; }
    inline const IndexBuffer &GetIndexBuffer() const { return *m_Ib; }
};
