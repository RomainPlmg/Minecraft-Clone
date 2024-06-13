#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Transformable.h"
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

class Cube : public Transformable {
private:
    void Init(const std::string &texturePath);

    VertexArray *m_Va;
    VertexBuffer *m_Vb;
    VertexBufferLayout *m_Layout;
    IndexBuffer *m_Ib;
    Texture *m_Texture;

    std::array<GLfloat, 192> m_VertexDatas;
    std::vector<GLuint> m_Indices;

public:
    /* Constructor */
    Cube();
    Cube(const std::string &texturePath);

    /* Methods */
    void RemoveFace(CubeFace face);
    void AddFace(CubeFace face);
    void ResetFaces();

    /* Getters */
    inline VertexArray &GetVertexArray() const { return *m_Va; }
    inline IndexBuffer &GetIndexBuffer() const { return *m_Ib; }
    inline Texture &GetTexture() const { return *m_Texture; }

    /* Setters */
    inline void SetTexture(const std::string &texturePath) { m_Texture->LoadFromFile(texturePath); }
};