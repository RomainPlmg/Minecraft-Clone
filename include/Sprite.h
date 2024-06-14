#pragma once

#include "Transformable.h"
#include "Drawable.h"
#include "Texture.h"

#include <array>

class Sprite: public Transformable, public Drawable {
private:
    void Init(const std::string &texturePath);
    std::array<GLfloat, 32> m_VertexDatas{};
public:
    Sprite();
    Sprite(const std::string &texturePath);

    /* Getters */
    inline virtual int GetType() const override { return SPRITE; }
};
