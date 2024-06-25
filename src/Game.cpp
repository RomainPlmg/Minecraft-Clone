#include "Game.h"
#include "Chunk.h"
#include "Sprite.h"

Game::Game() : m_Window(nullptr) {
    Setup(1280, 720);
    Run();
    Exit();
}

void Game::Setup(const int width, const int height) {
    m_Window  = new Window("Minecraft", width, height);

    // Init the time
    Timer::init();
}

void Game::Run() {
    Texture crossTex;
    Texture dirtTex;
    crossTex.LoadFromFile("../assets/textures/ui/crosshair.png");
    dirtTex.LoadFromFile("../assets/textures/block/stone.png");

    Sprite crosshair(crossTex);
    crosshair.Scale(glm::vec3(0.06f, 0.04f, 0.0f));

    Chunk chunk(glm::vec2(0, 0));

    chunk.Update();

    m_Window->GetRenderer().GetCamera().SetPosition(glm::vec3(0, CHUNK_Y+1, 0));
    m_Window->GetRenderer().GetCamera().SetYaw(glm::radians(360.0f));


    while (m_Window->IsOpen()) {
        Timer::update();
        /* Render here */
        m_Window->Clear(Color::Blue);

        m_Window->ProcessInput();

        chunk.Draw(m_Window->GetRenderer());
        crosshair.Draw(m_Window->GetRenderer());

        /* Swap front and back buffers */
        m_Window->Display();

        /* Poll for and process events */
        m_Window->PollEvents();
    }
}

void Game::Exit() {
    m_Window->Close();
}

