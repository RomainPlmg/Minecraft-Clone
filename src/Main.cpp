#include <stdexcept>
#include <iostream>
#include "Game.h"

int main(void) {
	try {
		Game minecraft(1280, 720);
	}
	catch (const std::runtime_error& error) {
		std::cerr << "An exception was throw: " << error.what() << "\n";
	}
	return 0;
}