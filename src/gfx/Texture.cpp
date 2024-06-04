#include "OpenGL.h"
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <iostream>

Texture::Texture(): m_RendererID(0), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0) {
    stbi_set_flip_vertically_on_load(true);

    GLCall(glGenTextures(1, &m_RendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
}

Texture::~Texture() {
    GLCall(glDeleteTextures(1, &m_RendererID));
}

int Texture::LoadFromFile(const std::string& path) {
    m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

    if (m_LocalBuffer) {
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
        GLCall(glGenerateMipmap(GL_TEXTURE_2D));
        stbi_image_free(m_LocalBuffer);
        return 0;
    }
    else {
        std::cerr << "Failed to load texture\n";
        return 1;
    }
}

void Texture::Bind(unsigned int slot) const {
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));
}

void Texture::Unbind() const {

}