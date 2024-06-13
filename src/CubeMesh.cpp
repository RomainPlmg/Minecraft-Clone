#include "CubeMesh.h"
#include <algorithm>

void CubeMesh::AddCube(Cube& cube) {
    this->m_Cubes.push_back(cube);
}

void CubeMesh::RemoveCube(glm::vec3& position) {
    auto it = m_Cubes.begin();
    for (it; it < m_Cubes.end(); it++) {
        if (it->GetPosition() == position) {
            m_Cubes.erase(it);
            break;
        }
    }
}

std::vector<CubeFace> CubeMesh::IsNeighbor(Cube& cube) {
    std::vector<CubeFace> faces;

    auto cubePosition = cube.GetPosition();
    for (const auto& otherCube: m_Cubes) {
        auto otherCubePosition = otherCube.GetPosition();

        if (cubePosition.x + 1 == otherCubePosition.x && std::find(faces.begin(), faces.end(), FACE_RIGHT) == faces.end())
            faces.push_back(FACE_RIGHT);
        if (cubePosition.x - 1 == otherCubePosition.x && std::find(faces.begin(), faces.end(), FACE_LEFT) == faces.end())
            faces.push_back(FACE_LEFT);
        if (cubePosition.y + 1 == otherCubePosition.y && std::find(faces.begin(), faces.end(), FACE_TOP) == faces.end())
            faces.push_back(FACE_TOP);
        if (cubePosition.y - 1 == otherCubePosition.y && std::find(faces.begin(), faces.end(), FACE_BOTTOM) == faces.end())
            faces.push_back(FACE_BOTTOM);
        if (cubePosition.z + 1 == otherCubePosition.z && std::find(faces.begin(), faces.end(), FACE_FRONT) == faces.end())
            faces.push_back(FACE_FRONT);
        if (cubePosition.z - 1 == otherCubePosition.z && std::find(faces.begin(), faces.end(), FACE_BACK) == faces.end())
            faces.push_back(FACE_BACK);
    }
    return faces;
}

void CubeMesh::CullingInvisibleFaces() {
    auto it = m_Cubes.begin();
    for (it; it < m_Cubes.end(); it++) {
        std::vector<CubeFace> invisibleFaces;
        invisibleFaces = IsNeighbor(*it);

        for (const auto& face : invisibleFaces) {
            it->RemoveFace(face);
        }
    }
}