#include "Cube.h"

Cube::Cube(const std::string& texturePath) {
	    float vertexDatas[192] = {
        // position				// color			// texture
        -0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Front face
         0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 1.0f,

         0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Right face
         0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 1.0f,

         0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Back face
        -0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
         0.5f,	0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 1.0f,

        -0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Left face
        -0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
        -0.5f,	0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 1.0f,

        -0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Top face
         0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f,	0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 1.0f,

        -0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Bottom face
         0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 0.0f,	0.0f, 1.0f,
    };
    unsigned int indices[36] = {
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

	m_Vb = new VertexBuffer(vertexDatas, sizeof(vertexDatas));
	m_Ib = new IndexBuffer(indices, sizeof(indices) / sizeof(unsigned int));
    m_Layout = new VertexBufferLayout;
    m_Va = new VertexArray;
    m_Texture = new Texture;

	m_Layout->Push<float>(3); // Position
    m_Layout->Push<float>(3); // Color
    m_Layout->Push<float>(2); // Texture
    m_Va->AddBuffer(*m_Vb, *m_Layout);

	m_Shader = new Shader("../assets/shaders/vertex.glsl", "../assets/shaders/fragment.glsl");
	m_Texture->LoadFromFile(texturePath);
}


/* Getters */
VertexArray* Cube::GetVertexArray() const {
	return m_Va;
}

IndexBuffer* Cube::GetIndexBuffer() const {
	return m_Ib;
}

Shader* Cube::GetShader() const {
	return m_Shader;
}