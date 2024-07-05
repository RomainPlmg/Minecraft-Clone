#pragma once

#include "OpenGL.h"
#include "Renderer.h"
#include "Camera.h"
#include "Utils.h"

class Window {
private:
    /* The init function is a common code for all constructors */
    void Init(const char* title, int width, int height);

    /* Callback function for GLFW */
    static void _size_callback(GLFWwindow* window, int width, int height);
    static void _error_callback(int code, const char* description);

    /* Attributes */
    GLFWmonitor *m_Monitor;
    const GLFWvidmode *m_VideoMode;
    GLFWwindow *m_Handle;
    Renderer *m_Renderer;

    glm::vec2 m_Size;
    int m_SizeWindowedX, m_SizeWindowedY;
    int m_PosWindowedX, m_PosWindowedY;

    std::string m_Title;
    double m_MousePosX, m_MousePosY, m_OldMousePosX, m_OldMousePosY;
    

    double m_timeForTwoFPS;
    bool m_keyPressed;
    bool m_IsFullscreen;
public:
    /* Constructors */
    Window();
    Window(const char* title);
    Window(const char* title, int width, int height);

    /* Destructor */
    ~Window();

    /* Methods */
    void Clear();
    void Clear(std::uint8_t r, std::uint8_t g, std::uint8_t b);
    void Clear(Color color);
    void PollEvents();
    void ProcessInput();
    void Display();
    void Close();
    bool IsOpen() const;

    /* Getters */
    inline Renderer& GetRenderer() const { return *m_Renderer; }
    inline glm::vec2 GetSize() const { return m_Size; }
};