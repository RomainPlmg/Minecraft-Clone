#version 460 core
layout (location = 0) in vec3 aPos; // The position variable has attribute position 0
layout (location = 1) in vec2 aTex; // The texture variable has attribute position 2

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

out vec2 textureCoord;

void main() {
    textureCoord = aTex;
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0);
}