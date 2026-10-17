#pragma once
#include <vector>
#include "pixel.h"

struct Dimensions {
    int height, width;
};

class Image {

    public:
        Dimensions dimensions;
        int channel_amount;
        std::vector<std::vector<Pixel>> pixel_field;
        
    Image(std::vector<std::vector<Pixel>> pixel_field, Dimensions dimensions, int channel_amount) :
    pixel_field(pixel_field), dimensions(dimensions), channel_amount(channel_amount) 
    { 
    }

    Image() : dimensions{0,0}, channel_amount(0) 
    {
    }

    ~Image() {
        
    }

};