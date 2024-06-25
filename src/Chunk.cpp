#include "Chunk.h"

Chunk::Chunk(glm::vec2 position) : m_Position(glm::vec2(position.x * 16, position.y * 16)) {
    m_Layout->Push<GLfloat>(3); // Position
    m_Layout->Push<GLfloat>(2); // Texture
    m_Texture = new Texture();
    m_Texture->LoadFromFile("../assets/textures/block/stone.png");
    m_Blocks = new Block[NB_BLOCKS_CHUNK](STONE);

    for (int x = 0; x < CHUNK_X; x++) {
        for (int y = 0; y < CHUNK_Y; y++) {
            for (int z = 0; z < CHUNK_Z; z++) {
                int index = x * (CHUNK_Y * CHUNK_Z) + y * CHUNK_Z + z;
                m_Blocks[index].SetPosition(glm::vec3(m_Position.x, 0, m_Position.y) + glm::vec3(x, y, z));
            }
        }
    }
}

void Chunk::Update() {
    int faceOffset = 0;
    for (int i = 0; i < NB_BLOCKS_CHUNK; i++) {
        if (m_Blocks[i].GetID() != AIR) {
            for (Direction d = NORTH; d < 6; d = static_cast<Direction>(d + 1)) {
                if (IsBlockInChunkBound(m_Blocks[i], d)) {
                    AddFace(m_Blocks[i].GetPosition(), d);
                } else {
                    glm::vec3 neighborPos = m_Blocks[i].GetPosition() + DIR2VEC3(d);
                    int neighborIndex = (int)neighborPos.x * (CHUNK_Y * CHUNK_Z) + (int)neighborPos.y * CHUNK_Z + (int)neighborPos.z;
                    if (neighborIndex <= NB_BLOCKS_CHUNK && m_Blocks[neighborIndex].GetID() == AIR) {
                        AddFace(m_Blocks[i].GetPosition(), d);
                    }
                }
            }
        }
    }
    m_Va->Reset();
    m_Vb->Update(m_Vertices.data(), m_Vertices.size() * sizeof(GLfloat));
    m_Ib->Update(m_Indices.data(), m_Indices.size());
    m_Va->AddBuffer(*m_Vb, *m_Layout);
}

void Chunk::Draw(const Renderer &renderer) {
    m_Va->Bind();
    m_Ib->Bind();
    m_Texture->Bind();

    Shader shader = renderer.GetShader(SHADER_BASIC_TEXTURE);
    shader.Bind();
    shader.SetUniformMat4fv("modelMatrix", glm::mat4(1.0f));
    shader.SetUniformMat4fv("viewMatrix", renderer.GetCamera().GetViewMatrix());
    shader.SetUniformMat4fv("projMatrix", renderer.GetProjMatrix());

    GLCall(glDrawElements(GL_TRIANGLES, m_Ib->GetCount(), GL_UNSIGNED_INT, nullptr));
}

bool Chunk::IsBlockInChunkBound(const Block &block, Direction d) {
    glm::vec3 cubePosition = block.GetPosition();
    if (cubePosition.x == 0 && d == WEST) return true;
    if (cubePosition.x == CHUNK_X-1 && d == EAST) return true;
    if (cubePosition.y == 0 && d == DOWN) return true;
    if (cubePosition.y == CHUNK_Y-1 && d == UP) return true;
    if (cubePosition.z == 0 && d == NORTH) return true;
    if (cubePosition.z == CHUNK_Z-1 && d == SOUTH) return true;

    return false;
}

void Chunk::AddFace(const glm::vec3& position, Direction d) {
    for (int y = 0; y < 12; y += 3) {
        m_Vertices.push_back(BLOCK_VERTICES[d * 12 + y] + position.x);
        m_Vertices.push_back(BLOCK_VERTICES[d * 12 + y + 1] + position.y);
        m_Vertices.push_back(BLOCK_VERTICES[d * 12 + y + 2] + position.z);

        m_Vertices.push_back(BLOCK_UV[(y / 3) * 2]);
        m_Vertices.push_back(BLOCK_UV[(y / 3) * 2 + 1]);
    }

    for (int y = 0; y < 6; y++) {
        m_Indices.push_back(FACE_INDICES[y] + (m_Indices.size() / 6) * 4);
    }
}