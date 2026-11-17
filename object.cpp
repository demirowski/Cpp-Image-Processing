#include "object.h"

int Object::max_ID = 0;

Object::Object(int rd, Vector2d cd, Shapes sh, Color cl) 
: radius(rd), coordinates(cd), color(cl), shape(sh), ID(++max_ID)
{
}

Object::~Object() {}

Shapes Object::getShape() {
    return shape;
}

const Vector2d Object::getCoordinates() const {
    return coordinates;
}

void Object::setCoordinates(Vector2d cd) {
    coordinates = cd;
}

void Object::moveCoordinates(Vector2d displacement) {
    coordinates = coordinates + displacement;
}

const int Object::getRadius() const {
    return radius;
}

const Color Object::getColor() const {
    return color;
}