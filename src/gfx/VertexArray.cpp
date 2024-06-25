#include "VertexArray.h"

VertexArray::VertexArray() : m_RendererID(0) {
    GLCall(glGenVertexArrays(1, &m_RendererID));
    Bind();
}

VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const {
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    uintptr_t offset = 0;
    for (int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (void*)offset));
        GLCall(glEnableVertexAttribArray(i));
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::Reset() {
    Unbind();
    GLCall(glDeleteVertexArrays(1, &m_RendererID));
    GLCall(glGenVertexArrays(1, &m_RendererID));
    Bind();
}


void VertexArray::Bind() const {
    GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const {
    GLCall(glBindVertexArray(0));
}