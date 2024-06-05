#pragma once

class Timer {
private:
    static double lastTime;
    static double deltaTime;
public:
    static double frameTime;
    static void init();
    static void update();
    inline static double getDeltaTime() { return deltaTime; }
};