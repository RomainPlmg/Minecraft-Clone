#include "OpenGL.h"
#include "Utils.h"
#include "Window.h"
#include <iomanip>
#include <sstream>

void Window::Init(const char* title, int width, int height) {
    this->m_Size.x = width;
    this->m_Size.y = height;
    this->m_Title = title;
    this->m_FOV = 45.0f;

    m_ProjMatrix = glm::perspective(glm::radians(m_FOV), (float)width / (float)height, 0.1f, 100.0f);

    if (!glfwInit()) {
        throw std::runtime_error("Failed to init GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Handle = glfwCreateWindow(m_Size.x, m_Size.y, m_Title.c_str(), nullptr, nullptr);
    if (!m_Handle) {
        throw std::runtime_error("Failed to create window");
    }

    /* Make the OpenGL context */
    glfwMakeContextCurrent(m_Handle);

    glfwSetWindowUserPointer(m_Handle, this);

    /* Configure callbacks */
    glfwSetFramebufferSizeCallback(m_Handle, _size_callback);
    glfwSetErrorCallback(_error_calback);

    GLInit();

    glfwSetInputMode(m_Handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwGetCursorPos(m_Handle, &m_OldMousePosX, &m_OldMousePosY);
    
    /* Build the camera and the renderer after making OpenGL context */
    m_Camera = new Camera();
    m_Renderer = new Renderer();
    timeForTwoFPS = glfwGetTime();
}


/* Constructors */
Window::Window(): m_Size(800, 600) {
    Init("Game", m_Size.x, m_Size.y);
}

Window::Window(const char* title): m_Size(800, 600) {
    Init(title, m_Size.x, m_Size.y);
}

Window::Window(const char* title, int width, int height): m_Size(width, height) {
    Init(title, m_Size.x, m_Size.y);
}


/* Methods */
void Window::Clear() {
    m_Renderer->Clear(0.0f, 0.0f, 0.0f);
}

void Window::Clear(std::uint8_t r, std::uint8_t g, std::uint8_t b) {
    m_Renderer->Clear(1.0f/(float)r, 1.0f/(float)g, 1.0f/(float)b);
}

void Window::Clear(Color color) {
    m_Renderer->Clear(color.r, color.g, color.b);
}

void Window::Draw(Cube& cube) {
    m_Renderer->GetShader().SetUniformMat4fv("viewMatrix", m_Camera->GetViewMatrix());
    m_Renderer->GetShader().SetUniformMat4fv("projectionMatrix", m_ProjMatrix);
    m_Renderer->Draw(cube);
}

void Window::PollEvents() {
    glfwPollEvents();
}

void Window::ProcessInput() {
    if (glfwGetKey(m_Handle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_Handle, true);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_W) == GLFW_PRESS) {
        m_Camera->ProcessKeyboard(FORWARD);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_A) == GLFW_PRESS) {
        m_Camera->ProcessKeyboard(LEFT);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_S) == GLFW_PRESS) {
        m_Camera->ProcessKeyboard(BACKWARD);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_D) == GLFW_PRESS) {
        m_Camera->ProcessKeyboard(RIGHT);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_SPACE) == GLFW_PRESS) {
        m_Camera->ProcessKeyboard(UP);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        m_Camera->ProcessKeyboard(DOWN);
    }
    
    glfwGetCursorPos(m_Handle, &m_MousePosX, &m_MousePosY);
    m_Camera->ProcessMouseMovement(m_MousePosX - m_OldMousePosX, m_OldMousePosY - m_MousePosY);
    m_OldMousePosX = m_MousePosX;
    m_OldMousePosY = m_MousePosY;
}

void Window::Display() {
    if (Timer::frameTime - timeForTwoFPS >= 0.5f) {
        std::stringstream windowTextStream;
        windowTextStream << m_Title << " " << std::fixed << std::setprecision(1) << 1.0f/Timer::getDeltaTime() << "FPS";
        std::string windowText = windowTextStream.str();
        glfwSetWindowTitle(m_Handle, windowText.c_str());

        timeForTwoFPS = Timer::frameTime;
    }
    glfwSwapBuffers(m_Handle);
}

void Window::Close() {
    glfwDestroyWindow(m_Handle);
    glfwTerminate();
}

bool Window::IsOpen() const {
    return !glfwWindowShouldClose(m_Handle);
}


/* Static methods */
void Window::_size_callback(GLFWwindow* window, int width, int height) {
    GLCall(glViewport(0, 0, width, height));
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    win->m_Size.x = width;
    win->m_Size.y = height;
    win->m_ProjMatrix = glm::perspective(glm::radians(win->m_FOV), (float)width / (float)height, 0.1f, 100.0f);
}

void Window::_error_calback(int code, const char* description) {
    std::string errorMsg = "Error " + std::to_string(code) + ": " + description + "\n";
    throw std::runtime_error(errorMsg.c_str());
}