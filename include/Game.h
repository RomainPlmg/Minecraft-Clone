#pragma once

#include "Window.h"

class Game {
private:
    Window *m_Window;
public:
    Game();
    void Setup(int width = 640, int height = 360);
    void Run();
    void Exit();
};