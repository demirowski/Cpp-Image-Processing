#pragma once
#include "object.h"

class LSource : public Object {
    
    private:
        float strength;
        // float attenuation_rate;
    
    public:

        LSource(Coordinates coordinate, Shapes sh, Color cl, float strength);
        ~LSource();

};