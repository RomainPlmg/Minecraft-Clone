#pragma once

#include "OpenGL.h"
#include "Renderer.h"
#include "Utils.h"

class Window {
private:
private:
    /* The init function is a common code for all constructors */
    void Init(const char* title, int width, int height);

    /* Callback function for GLFW */
    static void _size_callback(GLFWwindow* window, int width, int height);
    static void _error_calback(int code, const char* description);

    /* Attributes */
    GLFWwindow* m_Handle;
    glm::vec2 m_Size;
    Renderer* m_Renderer;
    glm::mat4 m_ProjMatrix;

    float m_FOV;
public:
    /* Constructors */
    Window();
    Window(const char* title);
    Window(const char* title, int width, int height);

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
     * @brief Draw something to the screen
    */
    void Draw(Cube& cube);

    /*
     * @brief Poll events
    */
    void PollEvents();

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