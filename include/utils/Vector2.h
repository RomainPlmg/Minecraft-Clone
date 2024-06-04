#pragma once

template <typename T>
class Vector2 {
private:
public:
	T x; // X coordinate of the vector
	T y; // Y coordinate of the vector

	Vector2(); // Default constructor
	Vector2(T X, T Y); // Construct the vector from its coordinates
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2u;