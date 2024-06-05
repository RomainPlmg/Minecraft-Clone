#include "Transformable.h"

void Transformable::Move(const glm::vec3& offset) {
    m_Position += offset;
}

void Transformable::Rotate(const glm::vec3& angle) {
    m_Angle += angle;
}

void Transformable::Scale(const glm::vec3& factor) {
    m_Scale += factor;
}

void Transformable::SetPosition(const float positionX, const float positionY, const float positionZ) {
    m_Position = glm::vec3(positionX, positionY, positionZ);
}

void Transformable::SetPosition(const glm::vec3& position) {
    m_Position = position;
}

void Transformable::SetRotation(const float rotationX, const float rotationY, const float rotationZ) {
    m_Angle = glm::vec3(rotationX, rotationY, rotationZ);
}

void Transformable::SetScale(const float scaleX, const float scaleY, const float scaleZ) {
    m_Scale = glm::vec3(scaleX, scaleY, scaleZ);
}

void Transformable::SetScale(const glm::vec3& scale) {
    m_Scale = scale;
}

void Transformable::SetOrigin(const float originX, const float originY, const float originZ) {
    m_Origin = glm::vec3(originX, originY, originZ);
}

void Transformable::SetOrigin(const glm::vec3& origin) {
    m_Origin = origin;
}