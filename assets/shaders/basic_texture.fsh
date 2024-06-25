#version 460 core
in vec2 textureCoord;
out vec4 FragColor;

uniform sampler2D stoneTexture;

void main() {
    FragColor = texture(stoneTexture, textureCoord);
}