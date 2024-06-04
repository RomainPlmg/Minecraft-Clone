#define GLFW_INCLUDE_NONE
#include "Renderer.h"

Renderer::Renderer() {
	GLCall(glEnable(GL_DEPTH_TEST)); // Enable the depth buffer to avoid OpenGL to overlap vertices in the drawing order
}

void Renderer::Draw(Cube& cube) const {

	glm::mat4 modelMatrix = glm::mat4(1.0f);

	modelMatrix = glm::translate(modelMatrix, glm::vec3(cube.GetPosition().x, cube.GetPosition().y, -5.0f));
	modelMatrix = glm::rotate(modelMatrix, glm::radians(cube.GetRotation()), glm::vec3(1.0f, 0.0f, 0.0f));

	cube.GetVertexArray()->Bind();
	cube.GetIndexBuffer()->Bind();

	cube.GetShader()->SetUniformMat4fv("modelMatrix", modelMatrix);

	cube.GetShader()->Bind();

	glDrawElements(GL_TRIANGLES, cube.GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear(float red, float green, float blue, float alpha) const {
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}