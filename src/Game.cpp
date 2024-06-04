#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include "Game.h"
#include "Cube.h"
#include "Window.h"

Game::Game(int width, int height) {
    Window window(width, height, "Minecraft");

    Cube exampleCube("../assets/textures/block/stone_bricks.png");

    VertexArray va;
    VertexBuffer vb(exampleCube.vertexDatas, sizeof(exampleCube.vertexDatas));
    VertexBufferLayout layout;
    IndexBuffer ib(exampleCube.indices, sizeof(exampleCube.indices) / sizeof(unsigned int));

    Renderer renderer;

    layout.Push<float>(3); // position
    layout.Push<float>(3); // color
    layout.Push<float>(2); // texture
    va.AddBuffer(vb, layout);

    Shader shader("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");

    auto modelMatrix = glm::mat4(1.0f);
    auto viewMatrix = glm::mat4(1.0f);
    auto projMatrix = glm::mat4(1.0f);

    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -5.0f));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(20.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    projMatrix = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

    // Init the time
    Timer::init();

    while (!glfwWindowShouldClose(window.GetHandler())) {
        Timer::update();
        /* Render here */
        renderer.Clear(0.3f, 0.5f, 0.85f, 1.0f);

        viewMatrix = glm::rotate(viewMatrix, glm::radians(20.0f * (float)Timer::getDeltaTime()), glm::vec3(0.0f, 1.0f, 0.0f));

        shader.SetUniformMat4fv("u_MVP", projMatrix * viewMatrix * modelMatrix);

        renderer.Draw(va, ib, shader);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.GetHandler());

        /* Poll for and process events */
        glfwPollEvents();
    }
    window.Destroy();
}