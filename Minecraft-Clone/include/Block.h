#pragma once

#include "Texture.h"
#include "Transformable.h"
#include <vector>

constexpr GLfloat BLOCK_VERTICES[72] {
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

constexpr GLfloat BLOCK_UV[8] {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
};

constexpr GLuint FACE_INDICES[36] {
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