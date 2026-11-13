#include "obstacle.h"

Obstacle::Obstacle(Coordinates coordinates, Shapes shape, int radius, Color color) 
: shape(shape), color(color), radius(radius), coordinates(coordinates)
{}

Obstacle::~Obstacle() 
{}

Coordinates Obstacle::getCoordinates() {
    return coordinates;
}

Shapes Obstacle::getShape() {
    return shape;
}

int Obstacle::getRadius() {
    return radius;
}