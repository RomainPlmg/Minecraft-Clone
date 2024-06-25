#include "OpenGL.h"
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <iostream>

Texture::Texture(const std::string& path): m_RendererID(0), m_Width(0), m_Height(0), m_BPP(0), m_Path(path) {
    stbi_set_flip_vertically_on_load(true);

    GLCall(glGenTextures(1, &m_RendererID));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

    if (m_Path != "NULL") {
        LoadFromFile(path);
    } else
    {
        LoadFromFile("../assets/textures/block/undefined.png");
    }
}

Texture::~Texture() {
    GLCall(glDeleteTextures(1, &m_RendererID));
}

int Texture::LoadFromFile(const std::string& path) {
    Bind();
    m_Path = path;
    unsigned char* localBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

    if (localBuffer) {
        GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
        GLCall(glGenerateMipmap(GL_TEXTURE_2D));
        stbi_image_free(localBuffer);
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
    GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}