#define GLFW_INCLUDE_NONE
#include "Renderer.h"

Renderer::Renderer() {
    GLCall(glEnable(GL_DEPTH_TEST)); // Enable the depth buffer to avoid OpenGL to overlap vertices in the drawing order
    GLCall(glEnable(GL_CULL_FACE));
}

void Renderer::Draw(VertexArray& va, IndexBuffer& ib, const Shader& shader) const {
    va.Bind();
    ib.Bind();
    shader.Bind();

    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear(float red, float green, float blue, float alpha) const {
    GLCall(glClearColor(red, green, blue, alpha));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}