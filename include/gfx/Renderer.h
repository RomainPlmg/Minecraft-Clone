#pragma once

#include "Shader.h"
#include "Camera.h"
#include <memory>
#include <map>

enum ShaderType {
    SHADER_NONE = 0,
    SHADER_CHUNK,
    SHADER_SKY,
    SHADER_BASIC_TEXTURE,
    SHADER_BASIC_COLOR
};

class Renderer {
private:
    glm::mat4 m_ProjMatrix;
    float m_FOV;

    Camera *m_Camera;
    std::map<ShaderType, std::unique_ptr<Shader>> m_Shaders;
public:
    Renderer(float width, float height);
    void Clear(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f) const;
    void UseShader(ShaderType) const;

    /* Getters */
    Shader& GetShader(ShaderType type) const;
    inline Camera& GetCamera() const { return *m_Camera; }
    inline glm::mat4 GetProjMatrix() const { return m_ProjMatrix; }
    inline float GetFOV() const { return m_FOV; }
};