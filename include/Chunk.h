#pragma once

#include "Drawable.h"
#include "Utils.h"
#include "Block.h"

constexpr int CHUNK_X = 16;
constexpr int CHUNK_Y = 256;
constexpr int CHUNK_Z = 16;
constexpr int NB_BLOCKS_CHUNK = CHUNK_X * CHUNK_Y * CHUNK_Z;

class Chunk final : public Drawable {
private:
    glm::vec2 m_Position;

    Block *m_Blocks;

    std::vector<GLfloat> m_Vertices;
    std::vector<GLuint> m_Indices;

    // Temporary
    Texture *m_Texture;

    /* Methods */
    bool IsBlockInChunkBound(const Block& block, Direction d);
    void AddFace(const glm::vec3& position, Direction d);

public:
    /* Constructor */
    Chunk(glm::vec2 position);

    /* Methods */
    void Update();
    void Draw(const Renderer &renderer) override;

    /* Getters */
    inline Block& GetCube(const glm::vec3& position) {return m_Blocks[(int)position.x * (CHUNK_Y * CHUNK_Z) + (int)position.y * CHUNK_Z + (int)position.z]; }
};