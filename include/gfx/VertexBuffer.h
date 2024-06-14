#pragma once

class VertexBuffer {
private:
    unsigned int m_RendererID;
public:
    VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    /* Methods */
    void Update(const void* data, unsigned int size);
    void Bind() const;
    void Unbind() const;
};