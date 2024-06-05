#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include "OpenGL.h"
#include "Game.h"
#include "Camera.h"
#include "Cube.h"
#include "Window.h"

Game::Game(int width, int height) {
    Window window("Minecraft", width, height);

    Cube exampleCube("../assets/textures/block/stone_bricks.png");

    // Init the time
    Timer::init();

    while (window.IsOpen()) {
        Timer::update();
        /* Render here */
        window.Clear(Color::Blue);

        window.ProcessInput();

        window.Draw(exampleCube);

        /* Swap front and back buffers */
        window.Display();

        /* Poll for and process events */
        window.PollEvents();
    }

    window.Close();
}