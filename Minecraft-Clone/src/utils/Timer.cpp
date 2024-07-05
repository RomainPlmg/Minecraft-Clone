#include <GLFW/glfw3.h>
#include "Timer.h"

double Timer::lastTime = 0.0;
double Timer::deltaTime = 0.0;
double Timer::frameTime = 0.0;

void Timer::init() {
    lastTime = glfwGetTime();
    deltaTime = 0.0;
}

void Timer::update() {
    frameTime = glfwGetTime();
    deltaTime = frameTime - lastTime;
    lastTime = frameTime;
}