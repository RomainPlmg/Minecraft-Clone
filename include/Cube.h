#pragma once

#include "Texture.h"
#include "Transformable.h"
#include "Drawable.h"
#include <string>
#include <array>
#include <vector>

enum CubeFace {
    FACE_FRONT,
    FACE_RIGHT,
    FACE_BACK,
    FACE_LEFT,
    FACE_TOP,
    FACE_BOTTOM
};

class Cube : public Transformable, public Drawable {
private:
    void Init(const std::string &texturePath);

    /* Attributes */
    std::array<GLfloat, 192> m_VertexDatas{};

public:
    /* Constructor */
    Cube();
    Cube(const std::string &texturePath);

    /* Methods */
    void RemoveFace(CubeFace face);
    void AddFace(CubeFace face);
    void ResetFaces();

    /* Getters */
    inline virtual int GetType() const override { return CUBE; }
};