#include "OpenGL.h"
#include "Utils.h"
#include "Window.h"
#include <iomanip>
#include <sstream>

void Window::Init(const char* title, int width, int height) {
    m_Size.x = width;
    m_Size.y = height;
    m_Title = title;

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

    /* Disable VSync */
    glfwSwapInterval(0);

    glfwSetWindowUserPointer(m_Handle, this);

    /* Configure callbacks */
    glfwSetFramebufferSizeCallback(m_Handle, _size_callback);
    glfwSetErrorCallback(_error_callback);

    GLInit();

    glfwSetInputMode(m_Handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwGetCursorPos(m_Handle, &m_OldMousePosX, &m_OldMousePosY);

    /* Create the renderer */
    m_Renderer = new Renderer(m_Size.x, m_Size.y);

    m_Monitor = glfwGetPrimaryMonitor();
    m_VideoMode = glfwGetVideoMode(m_Monitor);
    m_timeForTwoFPS = glfwGetTime();
    m_keyPressed = false;
    m_IsFullscreen = false;
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


/* Destructor */
Window::~Window() {
    delete m_Renderer;
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

void Window::PollEvents() {
    glfwPollEvents();
}

void Window::ProcessInput() {
    /* Debug controls */
    if (glfwGetKey(m_Handle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_Handle, true);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_F3) == GLFW_PRESS && !m_keyPressed) {
        GLint mode[2];
        GLCall(glGetIntegerv(GL_POLYGON_MODE, mode));
        if (*mode == GL_FILL) {
            GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_LINE));
        } else if (*mode == GL_LINE) {
            GLCall(glPolygonMode(GL_FRONT_AND_BACK, GL_FILL));
        }
        m_keyPressed = true;
    }
    if(glfwGetKey(m_Handle, GLFW_KEY_F11) == GLFW_PRESS && !m_keyPressed) {
        if (m_IsFullscreen) {
            glfwSetWindowMonitor(m_Handle, nullptr, m_PosWindowedX, m_PosWindowedY, m_SizeWindowedX, m_SizeWindowedY, 0);
            m_IsFullscreen = false;
        } else {
            // Save position and scale of the window
            glfwGetWindowPos(m_Handle, &m_PosWindowedX, &m_PosWindowedY);
            glfwGetWindowSize(m_Handle, &m_SizeWindowedX, &m_SizeWindowedY);
            // Switch to full screen
            glfwSetWindowMonitor(m_Handle, m_Monitor, 0, 0, m_VideoMode->width, m_VideoMode->height, m_VideoMode->refreshRate);
            m_IsFullscreen = true;
        }
        m_keyPressed = true;
    }
        if (glfwGetKey(m_Handle, GLFW_KEY_F3) == GLFW_RELEASE && 
            glfwGetKey(m_Handle, GLFW_KEY_F11) == GLFW_RELEASE) {
        m_keyPressed = false;
    }


    /* Movement controls */
    if (glfwGetKey(m_Handle, GLFW_KEY_W) == GLFW_PRESS) {
        m_Renderer->GetCamera().ProcessKeyboard(NORTH);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_A) == GLFW_PRESS) {
        m_Renderer->GetCamera().ProcessKeyboard(WEST);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_S) == GLFW_PRESS) {
        m_Renderer->GetCamera().ProcessKeyboard(SOUTH);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_D) == GLFW_PRESS) {
        m_Renderer->GetCamera().ProcessKeyboard(EAST);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_SPACE) == GLFW_PRESS) {
        m_Renderer->GetCamera().ProcessKeyboard(UP);
    }
    if (glfwGetKey(m_Handle, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        m_Renderer->GetCamera().ProcessKeyboard(DOWN);
    }
    
    glfwGetCursorPos(m_Handle, &m_MousePosX, &m_MousePosY);
    m_Renderer->GetCamera().ProcessMouseMovement(m_MousePosX - m_OldMousePosX, m_OldMousePosY - m_MousePosY);
    m_OldMousePosX = m_MousePosX;
    m_OldMousePosY = m_MousePosY;
}

void Window::Display() {
    if (Timer::frameTime - m_timeForTwoFPS >= 0.5f) {
        std::stringstream windowTextStream;
        windowTextStream << m_Title << " " << std::fixed << std::setprecision(1) << 1.0f/Timer::getDeltaTime() << "FPS";
        std::string windowText = windowTextStream.str();
        glfwSetWindowTitle(m_Handle, windowText.c_str());

        m_timeForTwoFPS = Timer::frameTime;
    }
    glfwSwapBuffers(m_Handle);
}

void Window::Close() {
    if (m_Handle) {
        glfwDestroyWindow(m_Handle);
        m_Handle = nullptr;
    }
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
    win->m_Renderer->GetProjMatrix() = glm::perspective(glm::radians(win->m_Renderer->GetFOV()), (float)width / (float)height, 0.1f, 100.0f);
}

void Window::_error_callback(int code, const char* description) {
    std::string errorMsg = "Error " + std::to_string(code) + ": " + description + "\n";
    throw std::runtime_error(errorMsg.c_str());
}