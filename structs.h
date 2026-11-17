#pragma once
#include <cstdint>
#include "math.h"

// IMPORTANT!!!
// Project-wide convention: always (y / height / rows) first, then (x / width / columns).
// This applies to Coordinates, Dimensions and any {a, b} initialization.


struct Color {
    uint8_t r, g, b;

    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color LIGHT;
};

Color operator*(const Color& cl, double scalar);
Color operator*(double scalar, const Color& cl);


struct Coordinates {
    int y;
    int x;
};

struct Vector2d {
    double y;
    double x;
};

struct Dimensions {
    int height;
    int width;
};

enum Shapes {
    CIRCLE,
    RECTANGLE
};