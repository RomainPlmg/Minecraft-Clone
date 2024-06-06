#define GLFW_INCLUDE_NONE
#include "Renderer.h"

Renderer::Renderer(GLenum mode) {
    GLCall(glEnable(GL_DEPTH_TEST)); // Enable the depth buffer to avoid OpenGL to overlap vertices in the drawing order
    GLCall(glPolygonMode(GL_FRONT_AND_BACK, mode));
    GLCall(glLineWidth(2.5f));

    m_Shader = new Shader("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");
}

void Renderer::Draw(Cube& cube) const {
    glm::mat4 modelMatrix = glm::mat4(1.0f);

    modelMatrix = glm::translate(modelMatrix, glm::vec3(cube.GetPosition().x, cube.GetPosition().y, cube.GetPosition().z));


    modelMatrix = glm::rotate(modelMatrix, glm::radians(cube.GetRotation().x), glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(cube.GetRotation().y), glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(cube.GetRotation().z), glm::vec3(0.0f, 0.0f, 1.0f));

    cube.GetVertexArray().Bind();
    cube.GetIndexBuffer().Bind();

    m_Shader->SetUniformMat4fv("modelMatrix", modelMatrix);

    m_Shader->Bind();

    glDrawElements(GL_TRIANGLES, cube.GetIndexBuffer().GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear(float red, float green, float blue, float alpha) const {
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}