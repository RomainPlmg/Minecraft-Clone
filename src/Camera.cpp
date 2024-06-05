#include "Camera.h"
#include "Utils.h"

/* Private methods */
void Camera::UpdateCameraVectors() {
    /* Calculate the new Front vector */
    glm::vec3 front;
    front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    front.y = sin(glm::radians(m_Pitch));
    front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front = glm::normalize(front);

    /* 
     * Also re-calculate the Right and Up vector
     * Normalize the vectors, because their length gets closer to 0 
     * the more you look up or down which results in slower movement.
     */
    m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
    m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}

/* Constructors */
Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch):
m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
m_MovementSpeed(SPEED),
m_MouseSensitivity(SENSITIVITY),
m_Zoom(ZOOM) 
{
    m_Position = position;
    m_WorldUp = up;
    m_Yaw = yaw;
    m_Pitch = pitch;
    UpdateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch):
m_Front(glm::vec3(0.0f, 0.0f, -1.0f)),
m_MovementSpeed(SPEED),
m_MouseSensitivity(SENSITIVITY),
m_Zoom(ZOOM)
{
    m_Position = glm::vec3(posX, posY, posZ);
    m_WorldUp = glm::vec3(upX, upY, upZ);
    m_Yaw = yaw;
    m_Pitch = pitch;
    UpdateCameraVectors();
}


/* Methods */
void Camera::ProcessKeyboard(CameraMovement direction) {
    float velocity = m_MovementSpeed * Timer::getDeltaTime();

    switch (direction) {
    case FORWARD:
        m_Position += m_Front * velocity;
        break;
    case BACKWARD:
        m_Position -= m_Front * velocity;
        break;
    case LEFT:
        m_Position -= m_Right * velocity;
        break;
    case RIGHT:
        m_Position += m_Right * velocity;
        break;
    case UP:
        m_Position += m_Up * velocity;
        break;
    case DOWN:
        m_Position -= m_Up * velocity;
        break;
    
    default:
        break;
    }
}

void Camera::ProcessMouseMovement(double offsetX, double offsetY, bool constrainPitch) {
    offsetX *= m_MouseSensitivity;
    offsetY *= m_MouseSensitivity;

    m_Yaw   += offsetX;
    m_Pitch += offsetY;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch) {
        if (m_Pitch > 89.0f)
            m_Pitch = 89.0f;
        if (m_Pitch < -89.0f)
            m_Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    UpdateCameraVectors();
}