#include "math.h"

double distanceV(Vector2d v1, Vector2d v2) {
    return sqrt((v1.y - v2.y)*(v1.y - v2.y) + (v1.x - v2.x)*(v1.x - v2.x));
}