#pragma once
#include "object.h"

class LSource : public Object {
    
    private:
        double strength;
        double range;
        // float attenuation_rate;
    
    public:

        double getStrength();

        LSource(Coordinates coordinate, Shapes sh, Color cl, float strength);
        ~LSource();

};