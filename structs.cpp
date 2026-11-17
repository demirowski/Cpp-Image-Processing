#include "structs.h"

const Color Color::RED   = {255, 0, 0};
const Color Color::GREEN = {0, 255, 0};
const Color Color::BLUE  = {0, 0, 255};
const Color Color::LIGHT_BLUE = {139, 171, 217};
const Color Color::LIGHT = {52, 235, 146};
const Color Color::BLACK = {0, 0, 0};

Color operator*(const Color& cl, double scalar) {
    return Color {
        static_cast<uint8_t>(cl.r * scalar),
        static_cast<uint8_t>(cl.g * scalar),
        static_cast<uint8_t>(cl.b * scalar),
    };
}

Color operator*(double scalar, const Color& cl) {
    return Color {
        static_cast<uint8_t>(cl.r * scalar),
        static_cast<uint8_t>(cl.g * scalar),
        static_cast<uint8_t>(cl.b * scalar),
    };
}

Vector2d operator+(const Vector2d& v1, const Vector2d& v2) {
    return Vector2d {v1.y + v2.y, v1.x + v2.x};
}

Vector2d operator-(const Vector2d& v1, const Vector2d& v2) {
    return Vector2d {v1.y - v2.y, v1.x - v2.x};
}

Vector2d operator*(const Vector2d& v1, const double scalar) {
    return Vector2d{v1.y * scalar, v1.x * scalar};
}

Vector2d operator*(const double scalar, const Vector2d& v1) {
    return Vector2d{v1.y * scalar, v1.x * scalar};
}

Vector2d operator/(const Vector2d& v, double divider) {
    return Vector2d {v.y / divider, v.x / divider};
}

double dotProduct(const Vector2d& v1, const Vector2d& v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

double distanceV(Vector2d v1, Vector2d v2) {
    return sqrt((v1.y - v2.y)*(v1.y - v2.y) + (v1.x - v2.x)*(v1.x - v2.x));
}