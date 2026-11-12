#pragma once
#include "structs.h"

class LSource {
    
    private:
        Coordinates coordinate;
        float strength;
        // float attenuation_rate;
        Color color;
    
    public:
        LSource(Coordinates coordinate, float strength);
        ~LSource();

};