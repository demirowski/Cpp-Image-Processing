#pragma once
#include "structs.h"

class Object {

    protected:
        int radius;
        Vector2d coordinates;
        Color color;
        Shapes shape;
        const int ID;
        static int max_ID;

    public:

        Shapes getShape();
        const Vector2d getCoordinates() const;
        const int getRadius() const;
        const Color getColor() const;
        void setCoordinates(Vector2d cd);
        void moveCoordinates(Vector2d displacement);


        Object(int rd, Vector2d cd, Shapes sh, Color cl);
        virtual ~Object();
};