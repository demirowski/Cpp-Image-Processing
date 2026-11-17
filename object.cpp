#include "object.h"

Object::Object(int rd, Coordinates cd, Shapes sh, Color cl) 
: radius(rd), coordinates(cd), color(cl), shape(sh)
{
}

Object::~Object() {}

Shapes Object::getShape() {
    return shape;
}

const Coordinates Object::getCoordinates() const {
    return coordinates;
}

const int Object::getRadius() const {
    return radius;
}

const Color Object::getColor() const {
    return color;
}