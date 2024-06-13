#include "Cube.h"

void Cube::Init(const std::string& texturePath) {
    
    this->m_VertexDatas = {
        // position             // color            // texture
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Front face
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 1.0f,

         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Right face
         0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 1.0f,

         0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Back face
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 1.0f,

        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Left face
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Top face
         0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 1.0f,

        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Bottom face
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,    0.0f, 1.0f
    };


    this->m_Indices = {
            0, 1, 3, // Front face
            1, 2, 3,

            4, 5, 7, // Right face
            5, 6, 7,

            8, 9, 11, // Back face
            9, 10, 11,

            12, 13, 15, // Left face
            13, 14, 15,

            16, 17, 19, // Top face
            17, 18, 19,

            20, 23, 21, // Bottom face
            21, 23, 22
    };

    this->m_Vb = new VertexBuffer(m_VertexDatas.data(), m_VertexDatas.size() * sizeof(GLfloat));
    this->m_Ib = new IndexBuffer(m_Indices.data(), m_Indices.size());
    this->m_Layout = new VertexBufferLayout;
    this->m_Va = new VertexArray;

    this->m_Layout->Push<GLfloat>(3); // Position
    this->m_Layout->Push<GLfloat>(3); // Color
    this->m_Layout->Push<GLfloat>(2); // Texture
    this->m_Va->AddBuffer(*this->m_Vb, *this->m_Layout);

    this->m_Texture = new Texture;
    this->m_Texture->LoadFromFile(texturePath);
}

/* Constructor */
Cube::Cube() {
    Init("../assets/textures/block/Undefined.png");
}

Cube::Cube(const std::string& texturePath) {
    Init(texturePath);
}

/* Methods */
void Cube::RemoveFace(CubeFace face) {
    if (m_Indices.empty()) return;
    auto it = m_Indices.begin();

    bool breakLoop = false;

    for (it; it < m_Indices.end(); it += 6) {
        switch (*it) {
            case 0:
                if (face == FACE_FRONT) breakLoop = true;
                break;
            case 4:
                if (face == FACE_RIGHT) breakLoop = true;
                break;
            case 8:
                if (face == FACE_BACK) breakLoop = true;
                break;
            case 12:
                if (face == FACE_LEFT) breakLoop = true;
                break;
            case 16:
                if (face == FACE_TOP) breakLoop = true;
                break;
            case 20:
                if (face == FACE_BOTTOM) breakLoop = true;
                break;
        }

        if (breakLoop) break;
    }

    /* Erase a face */
    for (int i = 0; i < 6; i++) {
        m_Indices.erase(it);
    }

    m_Ib->Update(m_Indices.data(), m_Indices.size());
}