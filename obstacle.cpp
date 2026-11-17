#include "obstacle.h"

Obstacle::Obstacle(Vector2d coordinates, Shapes shape, int radius, Color color) 
: Object(radius, coordinates, shape, color) 
{}

Obstacle::Obstacle() 
: Object(0, Vector2d{0,0}, CIRCLE, Color::BLACK)
{
}

Obstacle::~Obstacle() 
{}

