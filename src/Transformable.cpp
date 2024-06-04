#include "Transformable.h"

void Transformable::Move(const Vector2f& offset) {
    m_Position += offset;
}

void Transformable::Rotate(const float angle) {
    m_Angle += angle;
}

void Transformable::Scale(const Vector2f& factor) {
    m_Scale += factor;
}

void Transformable::SetPosition(const float positionX, const float positionY) {
    m_Position = Vector2f(positionX, positionY);
}

void Transformable::SetPosition(const Vector2f& position) {
    m_Position = position;
}

void Transformable::SetRotation(const float angle) {
    m_Angle = angle;
}

void Transformable::SetScale(const float scaleX, const float scaleY) {
    m_Scale = Vector2f(scaleX, scaleY);
}

void Transformable::SetScale(const Vector2f& scale) {
    m_Scale = scale;
}

void Transformable::SetOrigin(const float originX, const float originY) {
    m_Origin = Vector2f(originX, originY);
}

void Transformable::SetOrigin(const Vector2f& origin) {
    m_Origin = origin;
}