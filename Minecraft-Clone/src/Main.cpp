#include <stdexcept>
#include <iostream>
#include "Game.h"

int main(void) {
    try {
        Game minecraft;
    }
    catch (const std::runtime_error& error) {
        std::cerr << "An exception was throw: " << error.what() << "\n";
    }
    return 0;
}