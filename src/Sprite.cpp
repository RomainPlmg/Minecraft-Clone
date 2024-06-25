#include "Sprite.h"


void Sprite::Init(const Texture& texture) {
    m_Texture = &texture;

    m_Va->Bind();
    m_Vb->Update(SPRITE_VERTICES, 36 * sizeof(GLfloat));
    m_Ib->Update(SPRITE_INDICES, 6);
    m_Layout->Push<GLfloat>(3); // Position
    m_Layout->Push<GLfloat>(2); // Texture

    m_Va->AddBuffer(*m_Vb, *m_Layout);
}

Sprite::Sprite() : m_Texture(nullptr) {
    // Init(
}

Sprite::Sprite(const Texture& texture) : m_Texture(&texture) {
    Init(texture);
}

Sprite::~Sprite() {
    // delete m_Texture;
}

void Sprite::Draw(const Renderer &renderer) {
    m_Va->Bind();
    m_Ib->Bind();
    const Shader shader = renderer.GetShader(SHADER_BASIC_TEXTURE);
    shader.Bind();
    shader.SetUniformMat4fv("modelMatrix", m_ModelMatrix);
    shader.SetUniformMat4fv("viewMatrix", glm::mat4(1.0f));
    shader.SetUniformMat4fv("projMatrix", glm::mat4(1.0f));
    m_Texture->Bind();
    GLCall(glDrawElements(GL_TRIANGLES, m_Ib->GetCount(), GL_UNSIGNED_INT, nullptr));
}