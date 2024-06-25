#pragma once

#include "Texture.h"
#include "Transformable.h"
#include <vector>

constexpr std::array<GLfloat, 72> BLOCK_VERTICES {
         0.5f, -0.5f, -0.5f, // North face
        -0.5f, -0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f, // South face
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f, -0.5f,  0.5f, // East face
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f, // West face
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,

        -0.5f,  0.5f,  0.5f, // Up face
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,

        -0.5f, -0.5f, -0.5f, // Down face
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f
};

constexpr std::array<GLfloat, 8> BLOCK_UV {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
};

constexpr std::array<GLuint, 36> FACE_INDICES {
        0, 1, 3, 1, 2, 3
};

enum BlockID {
    UNDEFINED,
    AIR,
    DIRT,
    STONE
};

class Block : public Transformable {
private:
    Texture *m_Texture;
    BlockID m_ID;

public:
    /* Constructor */
    Block(BlockID id = UNDEFINED);

    /* Method */
    void Update(BlockID id);

    /* Setters */
    inline void SetTexture(Texture& texture) { m_Texture = &texture; }

    /* Getters */
    inline const Texture& GetTexture() const { return *m_Texture; }
    inline const BlockID GetID() const { return m_ID; }
};