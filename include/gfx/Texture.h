#pragma once

#include "OpenGL.h"
#include "Utils.h"

class Texture {
private:
    unsigned int m_RendererID;
    int m_Width, m_Height, m_BPP;
    std::string m_Path;
public:
    Texture(const std::string& path = "NULL");
    ~Texture();

    int LoadFromFile(const std::string& path);
    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline glm::vec2 GetSize() const { return {m_Width, m_Height}; }
    inline std::string& GetPath() { return m_Path; }
};