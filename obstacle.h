#pragma once
#include "object.h"


class Obstacle : public Object {

    private:


    public:

        Obstacle(Vector2d coordinates, Shapes shape, int radius, Color color);
        Obstacle();
        ~Obstacle();


};