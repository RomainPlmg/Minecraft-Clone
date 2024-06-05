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
    Cube exampleCube1("../assets/textures/block/stone_bricks.png");
    exampleCube1.Move(glm::vec3(2.0f, 0.0f, 0.0f));

    // Init the time
    Timer::init();

    while (window.IsOpen()) {
        Timer::update();
        /* Render here */
        window.Clear(Color::Blue);

        window.ProcessInput();

        window.Draw(exampleCube);
        window.Draw(exampleCube1);

        /* Swap front and back buffers */
        window.Display();

        /* Poll for and process events */
        window.PollEvents();
    }

    window.Close();
}