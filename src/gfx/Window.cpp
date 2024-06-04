#include <glad/glad.h>
#include "Window.h"

Window::Window(unsigned int width, unsigned int height, const std::string& title) {
    this->m_Size.x = width;
    this->m_Size.y = height;

    if (!glfwInit()) {
        throw std::runtime_error("Failed to init GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Handle = glfwCreateWindow(m_Size.x, m_Size.y, title.c_str(), nullptr, nullptr);
    if (!m_Handle) {
        throw std::runtime_error("Failed to create window");
    }

    /* Make the OpenGL context */
    glfwMakeContextCurrent(m_Handle);

    /* Configure callbacks */
    glfwSetFramebufferSizeCallback(m_Handle, _size_callback);
    glfwSetErrorCallback(_error_calback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

void Window::GameLoop() {

}

void Window::Destroy() {
    glfwTerminate();
}


/* Static methods */
void Window::_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Window::_error_calback(int code, const char* description) {
    std::string errorMsg = "GLFW error " + std::to_string(code) + ": " + description + "\n";
    throw std::runtime_error(errorMsg);
}