#pragma once

#include "Utils.h"

enum Direction {
    NORTH = 0,
    SOUTH,
    EAST,
    WEST,
    UP,
    DOWN
};

extern const glm::vec3 DIRECTION_VEC[6];

#define DIR2VEC3(d) (DIRECTION_VEC[d])