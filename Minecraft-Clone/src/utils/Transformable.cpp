#include "Transformable.h"

Transformable::Transformable() {
    this->m_ModelMatrix = glm::mat4(1.0f);

    this->m_Position = glm::vec3(0.0f);
    this->m_Angle = glm::vec3(0.0f);
    this->m_Scale = glm::vec3(0.0f);
    this->m_Origin = glm::vec3(0.0f);
}

void Transformable::Move(const glm::vec3& offset) {
    this->m_Position += offset;
    this->m_ModelMatrix = glm::translate(this->m_ModelMatrix, glm::vec3(offset.x, offset.y, offset.z));
}

void Transformable::Rotate(const glm::vec3& angle) {
    this->m_Angle += angle;
    this->m_ModelMatrix = glm::rotate(this->m_ModelMatrix, glm::radians(angle.x), glm::vec3(1.0f, 0.0f, 0.0f));
    this->m_ModelMatrix = glm::rotate(this->m_ModelMatrix, glm::radians(angle.y), glm::vec3(0.0f, 1.0f, 0.0f));
    this->m_ModelMatrix = glm::rotate(this->m_ModelMatrix, glm::radians(angle.z), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Transformable::Scale(const glm::vec3& factor) {
    this->m_Scale += factor;
    this->m_ModelMatrix = glm::scale(this->m_ModelMatrix, glm::vec3(factor.x, factor.y, factor.z));
}

void Transformable::SetPosition(const float positionX, const float positionY, const float positionZ) {
    this->m_Position = glm::vec3(positionX, positionY, positionZ);
    this->m_ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(positionX, positionY, positionZ));
}

void Transformable::SetPosition(const glm::vec3& position) {
    this->m_Position = position;
    this->m_ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, position.z));
}

void Transformable::SetRotation(const float rotationX, const float rotationY, const float rotationZ) {
    this->m_Angle = glm::vec3(rotationX, rotationY, rotationZ);
    this->m_ModelMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationX), glm::vec3(1.0f, 0.0f, 0.0f));
    this->m_ModelMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationY), glm::vec3(0.0f, 1.0f, 0.0f));
    this->m_ModelMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotationZ), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Transformable::SetScale(const float scaleX, const float scaleY, const float scaleZ) {
    this->m_Scale = glm::vec3(scaleX, scaleY, scaleZ);
    this->m_ModelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scaleX, scaleY, scaleZ));
}

void Transformable::SetScale(const glm::vec3& scale) {
    this->m_Scale = scale;
    this->m_ModelMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale.x, scale.y, scale.z));
}

void Transformable::SetOrigin(const float originX, const float originY, const float originZ) {
    this->m_Origin = glm::vec3(originX, originY, originZ);
}

void Transformable::SetOrigin(const glm::vec3& origin) {
    this->m_Origin = origin;
}