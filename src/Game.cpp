#define STB_IMAGE_IMPLEMENTATION

#include "Game.h"
#include "Camera.h"
#include "CubeMesh.h"
#include "Sprite.h"
#include "Window.h"

#define CUBE_SIZE 2

Game::Game(int width, int height) {
    Window window("Minecraft", width, height);
    CubeMesh mesh;

    for (int x = 0; x < CUBE_SIZE; x++) {
        for (int y = 0; y < CUBE_SIZE; y++) {
            for (int z = 0; z < CUBE_SIZE; z++) {
                Cube cube("../assets/textures/block/dirt.png");
                cube.SetPosition(glm::vec3(x, y, z));
                mesh.AddCube(cube);
            }
        }
    }

    Sprite crosshair("../assets/textures/ui/screen_cross.png");
    crosshair.Scale(glm::vec3(0.06f, 0.04f, 0.0f));

    mesh.CullingInvisibleFaces();

    // Init the time
    Timer::init();

    while (window.IsOpen()) {
        Timer::update();
        /* Render here */
        window.Clear(Color::Blue);

        window.ProcessInput();

        for (auto cube: mesh.GetCubes()) {
            window.Draw(cube);
        }

        window.Draw(crosshair);

        /* Swap front and back buffers */
        window.Display();

        /* Poll for and process events */
        window.PollEvents();
    }

    window.Close();
}