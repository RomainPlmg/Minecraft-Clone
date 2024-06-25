#include "Drawable.h"

Drawable::Drawable() : m_Vb(new VertexBuffer), m_Ib(new IndexBuffer), m_Layout(new VertexBufferLayout), m_Va(new VertexArray) {}

Drawable::~Drawable() {
    delete m_Vb;
    delete m_Ib;
    delete m_Layout;
    delete m_Va;
}
