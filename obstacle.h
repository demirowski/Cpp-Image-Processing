#pragma once
#include "structs.h"


class Obstacle {

    private:
        Coordinates coordinates;
        Shapes shape;
        Color color;
        int radius;

    public:

        Coordinates getCoordinates();
        Shapes getShape();
        int getRadius();

        Obstacle(Coordinates coordinates, Shapes shape, int radius, Color color);
        ~Obstacle();


};