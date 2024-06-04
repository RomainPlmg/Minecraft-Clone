#ifndef __CUBE_H__
#define __CUBE_H__


#include "gfx/Texture.h"
#include <string>

class Cube {
public:
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

private:
    Texture m_Texture;
    
public:
    Cube(const std::string& texturePath);
};

#endif // __CUBE_H__