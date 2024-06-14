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
    static void _error_calback(int code, const char* description);

    /* Attributes */
    GLFWmonitor* m_Monitor;
    const GLFWvidmode* m_VideoMode;
    GLFWwindow* m_Handle;
    Camera* m_Camera;
    Renderer* m_Renderer;
    Shader* m_Shader;

    glm::vec2 m_Size;
    int m_SizeWindowedX, m_SizeWindowedY;
    int m_PosWindowedX, m_PosWindowedY;

    glm::mat4 m_ProjMatrix;
    float m_FOV;

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

    ~Window();

    /*
     * @brief Clear the window with black color
    */
    void Clear();

    /*
     * @brief Clear the window with custom color
    */
    void Clear(std::uint8_t r, std::uint8_t g, std::uint8_t b);

    /*
     * @brief Clear the window with custom color
    */
    void Clear(Color color);

    /*
     * @brief Draw something on the screen
    */
    void Draw(Drawable &entity);

    /*
     * @brief Poll events
    */
    void PollEvents();

    /*
     * @brief Process all inputs, like keyboard or mouse
    */
    void ProcessInput();

    /*
     * @brief Display the window
    */
    void Display();

    /*
     * @brief Destroy the window
    */
    void Close();

    /*
     * @brief Check if the window is open
    */
    bool IsOpen() const;
};