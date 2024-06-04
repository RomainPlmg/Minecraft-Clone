#pragma once

template <typename T>
class Vector2 {
public:
    T x; // X coordinate of the vector
    T y; // Y coordinate of the vector

    constexpr Vector2(); // Default constructor
    constexpr Vector2(T X, T Y); // Construct the vector from its coordinates

    Vector2<T> operator+(const Vector2<T>& other) const;
    Vector2<T> operator-(const Vector2<T>& other) const;
    Vector2<T>& operator+=(const Vector2<T>& other);
    Vector2<T>& operator-=(const Vector2<T>& other);
    Vector2<T>& operator=(const Vector2<T>& other);

    friend class Vector2<float>;
    friend class Vector2<int>;
    friend class Vector2<unsigned int>;
};

template <typename T>
constexpr Vector2<T>::Vector2() : x(0), y(0) {}

template <typename T>
constexpr Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) const {
    return Vector2<T>(this->x + other.x, this->y + other.y);
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) const {
    return Vector2<T>(this->x - other.x, this->y - other.y);
}

template <typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

template <typename T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2u;