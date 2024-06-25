#pragma once

#include "Transformable.h"
#include "Drawable.h"
#include "Texture.h"
#include "Game.h"

constexpr GLfloat SPRITE_VERTICES[36] = {
    -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,    0.0f, 1.0f
};

constexpr GLuint SPRITE_INDICES[6] {
    0, 1, 3,
    1, 2, 3
};

class Sprite final: public Transformable, public Drawable {
private:
    const Texture *m_Texture;

public:
    Sprite();
    explicit Sprite(const Texture& texture);
    ~Sprite() override;

    /* Methods */
    void Init(const Texture& texture);
    void Draw(const Renderer &renderer) override;

    /* Setters */
    inline void SetTexture(const Texture& texture) { m_Texture = &texture; }
    inline const Texture& GetTexture() const { return *m_Texture; }
};
