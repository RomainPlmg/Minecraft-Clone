#include "Vector2.h"

template <>
Vector2<float>::Vector2() {
	x = 0.0f;
	y = 0.0f;
}

template <>
Vector2<int>::Vector2() {
	x = 0;
	y = 0;
}

template <>
Vector2<unsigned int>::Vector2() {
	x = 0;
	y = 0;
}

template <>
Vector2<float>::Vector2(float X, float Y) {
	x = X;
	y = Y;
}

template <>
Vector2<int>::Vector2(int X, int Y) {
	x = X;
	y = Y;
}

template <>
Vector2<unsigned int>::Vector2(unsigned int X, unsigned int Y) {
	x = X;
	y = Y;
}