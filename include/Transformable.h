#pragma once

#include "OpenGL.h"
#include "Utils.h"

class Transformable {
protected:
    glm::vec3 m_Position;
    glm::vec3 m_Angle;
    glm::vec3 m_Scale;
    glm::vec3 m_Origin;

    glm::mat4 m_ModelMatrix;
public:
    Transformable();
    virtual ~Transformable() = default;

    /* Methods */
    void Move(const glm::vec3& offset);
    void Rotate(const glm::vec3& angle);
    void Scale(const glm::vec3& factor);

    /* Setters */
    void SetPosition(const float positionX, const float positionY, const float positionZ);
    void SetPosition(const glm::vec3& position);
    void SetRotation(const float rotationX, const float rotationY, const float rotationZ);
    void SetRotation(const glm::vec3 angle);
    void SetScale(const float scaleX, const float scaleY, const float scaleZ);
    void SetScale(const glm::vec3& scale);
    void SetOrigin(const float originX, const float originY, const float originZ);
    void SetOrigin(const glm::vec3& origin);

    /* Getters */
    inline const glm::mat4& GetModelMatrix() const { return m_ModelMatrix; }
    inline const glm::vec3& GetPosition() const { return m_Position; }
    inline const glm::vec3& GetRotation() const { return m_Angle; }
    inline const glm::vec3& GetScale() const { return m_Scale; }
    inline const glm::vec3& GetOrigin() const { return m_Origin; }
};