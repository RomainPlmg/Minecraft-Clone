#include <iostream>
#include <glm/gtc/type_ptr.hpp>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "Renderer.h"

Renderer::Renderer() {
	glEnable(GL_DEPTH_TEST); // Enable the depth buffer to avoid OpenGL to overlap vertices in the drawing order
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {

	shader.Bind();
	va.Bind();
	ib.Bind();

	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear(float red, float green, float blue, float alpha) const {
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}