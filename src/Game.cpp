#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include "OpenGL.h"
#include "Game.h"
#include "Camera.h"
#include "Cube.h"
#include "Window.h"

Game::Game(int width, int height) {
    Window window("Minecraft", width, height);

    int chunkSize = 16;
    Cube* cubes = new Cube[chunkSize*chunkSize];

    for (int i = 0; i < chunkSize; i++) {
        for (int y = 0; y < chunkSize; y++) {
            int index = i * chunkSize + y;
            cubes[index].SetTexture("../assets/textures/block/dirt.png");
            cubes[index].SetPosition(glm::vec3(i, 0, y));
        }
    }

    // Init the time
    Timer::init();

    while (window.IsOpen()) {
        Timer::update();
        /* Render here */
        window.Clear(Color::Blue);

        window.ProcessInput();

        for (int i = 0; i < chunkSize; i++) {
            for (int y = 0; y < chunkSize; y++) {
                int index = i * chunkSize + y;
                window.Draw(cubes[index]);
            }
        }

        /* Swap front and back buffers */
        window.Display();

        /* Poll for and process events */
        window.PollEvents();
    }

    window.Close();
}