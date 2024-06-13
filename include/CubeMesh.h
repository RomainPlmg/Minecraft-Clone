#pragma once

#include "Cube.h"
#include <vector>

class CubeMesh {
private:
    std::vector<Cube> m_Cubes;
public:
    /* Methods */
    void AddCube(Cube& cube);
    void RemoveCube(glm::vec3& position);
    std::vector<CubeFace> IsNeighbor(Cube& cube);
    void CullingInvisibleFaces();

    /* Getters */
    inline std::vector<Cube> GetCubes() { return m_Cubes; }
};
