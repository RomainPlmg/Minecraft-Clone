#pragma once

#include "OpenGL.h"
#include "Utils.h"

class Transformable {
protected:
    Vector2f m_Position;
    float m_Angle;
    Vector2f m_Scale;
    Vector2f m_Origin;
public:
    Transformable() = default;
    virtual ~Transformable() = default;

    /* Methods */
    void Move(const Vector2f& offset);
    void Rotate(const float angle);
    void Scale(const Vector2f& factor);

    /* Setters */
    void SetPosition(const float positionX, const float positionY);
    void SetPosition(const Vector2f& position);
    void SetRotation(const float angle);
    void SetScale(const float scaleX, const float scaleY);
    void SetScale(const Vector2f& scale);
    void SetOrigin(const float originX, const float originY);
    void SetOrigin(const Vector2f& origin);

    /* Getters */
    inline const Vector2f& GetPosition() const { return m_Position; }
    inline float GetRotation() const { return m_Angle; }
    inline const Vector2f& GetScale() const { return m_Scale; }
    inline const Vector2f& GetOrigin() const { return m_Origin; }
};