#include "obstacle.h"

Obstacle::Obstacle(Coordinates coordinates, Shapes shape, int radius, Color color) 
: Object(radius, coordinates, shape, color) 
{}

Obstacle::~Obstacle() 
{}

