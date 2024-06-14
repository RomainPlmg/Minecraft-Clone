#include "Sprite.h"

void Sprite::Init(const std::string &texturePath) {
    m_VertexDatas = {
        // position             // color            // texture
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 1.0f
    };

    m_Indices = {
        0, 1, 3,
        1, 2, 3
    };

    m_Type = SPRITE;
    m_Vb = new VertexBuffer(m_VertexDatas.data(), m_VertexDatas.size() * sizeof(GLfloat));
    m_Ib = new IndexBuffer(m_Indices.data(), m_Indices.size());
    m_Layout = new VertexBufferLayout;
    m_Va = new VertexArray;

    m_Layout->Push<GLfloat>(3); // Position
    m_Layout->Push<GLfloat>(3); // Color
    m_Layout->Push<GLfloat>(2); // Texture
    m_Va->AddBuffer(*m_Vb, *m_Layout);

    m_Texture = new Texture;
    m_Texture->LoadFromFile(texturePath);
}

Sprite::Sprite() {
    Init("../assets/textures/block/Undefined.png");
}

Sprite::Sprite(const std::string &texturePath) {
    Init(texturePath);
}