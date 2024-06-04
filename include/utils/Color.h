#pragma once

#include <cstdint>

class Color {
public:
    /* Attributes */
    std::uint8_t r, g, b, a;

    constexpr Color(): r(0), g(0), b(0), a(255) {};
    constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255): r(r), g(g), b(b), a(a) {};

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};

inline const Color Color::Black = Color(0, 0, 0);
inline const Color Color::White = Color(255, 255, 255);
inline const Color Color::Red = Color(255, 0, 0);
inline const Color Color::Green = Color(0, 255, 0);
inline const Color Color::Blue = Color(0, 0, 255);