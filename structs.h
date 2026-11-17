#pragma once
#include <cstdint>

// IMPORTANT!!!
// Project-wide convention: always (y / height / rows) first, then (x / width / columns).
// This applies to Coordinates, Dimensions and any {a, b} initialization.


struct Color {
    uint8_t r, g, b;

    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
};


struct Coordinates {
    int y;
    int x;
};

struct Dimensions {
    int height;
    int width;
};

enum Shapes {
    CIRCLE,
    RECTANGLE
};