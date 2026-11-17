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
    static const Color LIGHT_BLUE;
    static const Color LIGHT;
    static const Color BLACK;
};

Color operator*(const Color& cl, double scalar);
Color operator*(double scalar, const Color& cl);

struct Vector2d {
    double y;
    double x;
};

Vector2d operator+(const Vector2d& v1, const Vector2d& v2);
Vector2d operator-(const Vector2d& v1, const Vector2d& v2);
Vector2d operator*(const Vector2d& v1, const double scalar);
Vector2d operator*(const double scalar, const Vector2d& v1);
Vector2d operator/(const Vector2d& v, double divider);

double dotProduct(const Vector2d& v1, const Vector2d& v2);
double distanceV(Vector2d v1, Vector2d v2);

struct Dimensions {
    int height;
    int width;
};

enum Shapes {
    CIRCLE,
    SQUARE
};