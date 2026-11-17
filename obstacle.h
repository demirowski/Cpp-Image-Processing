#pragma once
#include "object.h"


class Obstacle : public Object {

    private:


    public:

        Obstacle(Coordinates coordinates, Shapes shape, int radius, Color color);
        ~Obstacle();


};