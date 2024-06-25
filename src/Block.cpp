#include "Block.h"
#include "Game.h"
#include <memory>

/* Constructor */
Block::Block(BlockID id) : m_Texture(nullptr), m_ID(id) {}

void Block::Update(BlockID id) {
    m_ID = AIR;
}