#pragma once

// IMPORTANT!!!
// Project-wide convention: always (y / height / rows) first, then (x / width / columns).
// This applies to Coordinates, Dimensions and any {a, b} initialization.

enum Color {
    RED,
    GREEN,
    BLUE
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