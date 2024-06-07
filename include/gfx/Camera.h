#pragma once

#include "OpenGL.h"
#include "Utils.h"

enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

// Default camera values
const float YAW         = -90.0f;   // The rotation around the Y axis
const float PITCH       = 0.0f;     // The rotation around the X axis
const float SPEED       = 2.5f;     // Movement speed
const float SENSITIVITY = 0.3f;     // Sensitivity of the camera
const float ZOOM        = 45.0f;    // Zoom of the camera

class Camera {
private:
    glm::vec3 m_Position;
    glm::vec3 m_Front;
    glm::vec3 m_Up;
    glm::vec3 m_Right;
    glm::vec3 m_WorldUp;

    float m_Yaw;
    float m_Pitch;
    float m_MovementSpeed;
    float m_MouseSensitivity;
    float m_Zoom;

    void UpdateCameraVectors();
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    /* Methods */
    void ProcessKeyboard(CameraMovement direction);
    void ProcessMouseMovement(double offsetX, double offsetY, bool constrainPitch = true);

    /* Getters */
    inline glm::mat4 GetViewMatrix() { return glm::lookAt(m_Position, m_Position + m_Front, m_Up); }

    /* Setters */
    inline void SetPosition(glm::vec3 position) { m_Position = position; }
    inline void SetYaw(float angle) { m_Yaw = angle; }
    inline void SetPitch(float angle) { m_Pitch = angle; }
};