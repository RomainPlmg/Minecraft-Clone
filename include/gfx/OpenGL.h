#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLInit() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
} 

static void GLClearError() {
    while (glGetError() != GL_NO_ERROR);    
}

static bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::string errorMsg = "[OpenGL Error] (" + std::to_string(error) + function + " " + file + ": " + std::to_string(line) + "\n";
        throw std::runtime_error(errorMsg.c_str());
        return false;
    }
    return true;
}