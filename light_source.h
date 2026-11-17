#pragma once
#include "object.h"

class LSource : public Object {
    
    private:
        double strength;
        double range;
        bool on = false;
        Color light_color;
        // float attenuation_rate;
    
    public:

        double getStrength();
        void turnON();
        void turnOFF();
        bool getStatus();
        const Color getColor() const;

        LSource(Vector2d coordinate, Shapes sh, Color cl, float strength);
        ~LSource();

};