#pragma once
#include "structs.h"

enum Shapes {
    Circle,
    Rectangle
};



class Obstacle {

    private:
        Coordinates coordinates;
        Shapes shape;
        Color color;
        int radius;

    public:
        Obstacle(Shapes shape, int radius, Color color);
        ~Obstacle();


};