#pragma once
#include "structs.h"

class Object {

    protected:
        int radius;
        Coordinates coordinates;
        Color color;
        Shapes shape;

    public:

        Shapes getShape();
        const Coordinates getCoordinates() const;
        const int getRadius() const;
        const Color getColor() const;



        Object(int rd, Coordinates cd, Shapes sh, Color cl);
        virtual ~Object();
};