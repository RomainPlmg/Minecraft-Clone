#ifndef __TIME_H__
#define __TIME_H__

class Timer {
private:
    static double lastTime;
    static double deltaTime;
public:
    static void init();
    static void update();
    inline static double getDeltaTime() { return deltaTime; }
};

#endif // __TIME_H__