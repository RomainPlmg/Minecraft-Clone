#include "Drawable.h"

void Drawable::Bind() const {
    m_Texture->Bind();
    m_Vb->Bind();
    m_Ib->Bind();
}