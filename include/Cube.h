#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Shader.h"
#include "Transformable.h"
#include <string>

class Cube: public Transformable {
private:
    VertexArray* m_Va;
    VertexBuffer* m_Vb;
    VertexBufferLayout* m_Layout;
    IndexBuffer* m_Ib;
    Shader* m_Shader;
    Texture* m_Texture;
    
public:
    Cube(const std::string& texturePath);

    /* Getters */
    VertexArray* GetVertexArray() const;
    IndexBuffer* GetIndexBuffer() const;
    Shader* GetShader() const;
};