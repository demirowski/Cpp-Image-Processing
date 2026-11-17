#include "light_source.h"

LSource::LSource(Coordinates coordinate, Shapes sh, Color cl, float strength) 
: Object(10, coordinate, CIRCLE, Color::RED), strength(strength)
{
}

LSource::~LSource() {}

double LSource::getStrength() {
    return strength;
}