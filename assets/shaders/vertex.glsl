#version 460 core
layout (location = 0) in vec3 aPos; // The position variable has attribute position 0
layout (location = 1) in vec3 aCol; // The position variable has attribute position 0
layout (location = 2) in vec2 aTex; // The texture variable has attribute position 2

uniform mat4 u_MVP;

out vec2 textureCoord;

void main() {
    textureCoord = aTex;
    gl_Position = u_MVP * vec4(aPos, 1.0);
}