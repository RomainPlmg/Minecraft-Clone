#include "Renderer.h"

Renderer::Renderer(float width, float height) {
    GLCall(glEnable(GL_DEPTH_TEST)); // Enable the depth buffer to avoid OpenGL to overlap vertices in the drawing order
    GLCall(glEnable(GL_CULL_FACE));

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    m_FOV = 45.0f;
    m_ProjMatrix = glm::perspective(glm::radians(m_FOV), width / height, 0.1f, 100.0f);

    /* Build the camera and the renderer after making OpenGL context */
    m_Camera = new Camera();

    /* Create shader programs */
    m_Shaders[SHADER_NONE] = nullptr;
    m_Shaders[SHADER_BASIC_TEXTURE] = std::make_unique<Shader>("./assets/shaders/basic_texture.vsh", "./assets/shaders/basic_texture.fsh");
}

void Renderer::Clear(float red, float green, float blue, float alpha) const {
    GLCall(glClearColor(red, green, blue, alpha));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::UseShader(ShaderType type) const {
    auto it = m_Shaders.find(type);
    if(it != m_Shaders.end() && it->second) {
        it->second->Bind();
    } else {
        throw std::runtime_error("SHADER_NONE");
    }
}

/* Getters */
Shader& Renderer::GetShader(ShaderType type) const {
    auto it = m_Shaders.find(type);
    if (it != m_Shaders.end() && it->second) {
        return *(it->second);
    }
    throw std::runtime_error("Shader not found");
}