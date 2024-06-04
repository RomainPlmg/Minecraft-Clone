#include <iostream>
#include "Cube.h"

Cube::Cube(const std::string& texturePath) {
	m_Texture.LoadFromFile(texturePath);
}
