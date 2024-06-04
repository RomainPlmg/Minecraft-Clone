#pragma once

#include <GLFW/glfw3.h>
#include "Utils.h"

class Window {
private:
	GLFWwindow* m_Handle;
	Vector2u m_Size;

	static void _size_callback(GLFWwindow* window, int width, int height);
	static void _error_calback(int code, const char* description);

public:
	Window(unsigned int width, unsigned int height, const std::string& title);
	void GameLoop();
	void Destroy();

	inline GLFWwindow* GetHandler() { return m_Handle; }
	inline void SetSize(Vector2u size) { m_Size = size; }
	inline Vector2u GetSize() { return m_Size; }
};