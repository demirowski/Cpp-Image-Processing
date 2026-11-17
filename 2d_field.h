#pragma once
#include "light_source.h"
#include "obstacle.h"
#include <string>
#include <vector>
#include "pixel.h"
#include "math.h"

using namespace std;

class Field {
    private:
        vector<shared_ptr<LSource>> sources;
        vector<shared_ptr<Obstacle>> obstacles;
        Color bg_color = Color::BLACK;
        Dimensions dimensions;

        vector<vector<Pixel>> pixel_field;

    
    public:

        void add_light_source(Vector2d cd, Color cl, float strength);
        void move_lsource(int place, Vector2d displacement);

        void add_obstacle(Vector2d cd, Shapes sp, int radius, Color cl); 
        void move_obstacle(int place, Vector2d displacement);


        vector<shared_ptr<LSource>>& getLights();
        vector<shared_ptr<Obstacle>>& getObstacles();
        Dimensions getDimensions();
        vector<vector<Pixel>>& getPixelField();
        Color getColor();

        Field(Color cl, Dimensions dm);
        Field(Dimensions dm);
        ~Field();

        
    
};