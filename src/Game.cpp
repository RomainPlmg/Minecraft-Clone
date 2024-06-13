#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include "OpenGL.h"
#include "Game.h"
#include "Camera.h"
#include "Cube.h"
#include "Window.h"

#define CUBE_SIZE 5

Game::Game(int width, int height) {
    Window window("Minecraft", width, height);
    Cube* cubes = new Cube[(int)pow(CUBE_SIZE, 3)];

    for (int x = 0; x < CUBE_SIZE; x++) {
        for (int y = 0; y < CUBE_SIZE; y++) {
            for (int z = 0; z < CUBE_SIZE; z++) {
                int index = x * (CUBE_SIZE * CUBE_SIZE) + y * CUBE_SIZE + z;
                cubes[index].SetTexture("../assets/textures/block/dirt.png");
                cubes[index].SetPosition(glm::vec3(x, y, z));
            }
        }
    }

    // Init the time
    Timer::init();

    while (window.IsOpen()) {
        Timer::update();
        /* Render here */
        window.Clear(Color::Blue);

        window.ProcessInput();

        for (int x = 0; x < CUBE_SIZE; x++) {
            for (int y = 0; y < CUBE_SIZE; y++) {
                for (int z = 0; z < CUBE_SIZE; z++) {
                    int index = x * (CUBE_SIZE * CUBE_SIZE) + y * CUBE_SIZE + z;
                    window.Draw(cubes[index]);
                }
            }
        }

        /* Swap front and back buffers */
        window.Display();

        /* Poll for and process events */
        window.PollEvents();
    }

    delete[] cubes;

    window.Close();
}