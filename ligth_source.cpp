#include "light_source.h"

LSource::LSource(Vector2d coordinate, Shapes sh, Color cl, float strength) 
: Object(2, coordinate, CIRCLE, Color::RED), strength(strength), light_color(cl)
{
}

LSource::~LSource() {}

double LSource::getStrength() {
    return strength;
}

void LSource::turnON() {
    on = true;
}

void LSource::turnOFF() {
    on = false;
}

bool LSource::getStatus() {
    return on;
}

const Color LSource::getColor() const {
    return light_color;
}