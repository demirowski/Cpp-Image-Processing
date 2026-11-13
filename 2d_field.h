#pragma once
#include "light_source.h"
#include "obstacle.h"
#include <string>
#include <vector>
#include "pixel.h"
#include <cmath>

using namespace std;

class Field {
    private:
        vector<LSource> sources;
        vector<Obstacle> obstacles;
        Color bg_color;
        Dimensions dimensions;

        vector<vector<Pixel>> pixel_field;

    
    public:

        void print_image(string name = "result.png");
        void add_light_source(Coordinates cd, Color cl, float strength);
        void add_obstacle(Coordinates cd, Shapes sp, int radius, Color cl); 

        
        Dimensions getDimensions();

        Field(Color cl, Dimensions dm);
        Field(Dimensions dm);
        ~Field();

        
    
};