#include "light_source.h"
#include "obstacle.h"
#include "2d_field.h"
#include <iostream>


class SceneManager {

    private:
        vector<shared_ptr<Obstacle>>& obstacles;
        vector<shared_ptr<LSource>>& sources;
        vector<vector<Pixel>>& pixel_field;
        Dimensions dimensions;


    public:

        void draw_ray(Coordinates cd, double f);
        void turn_on_all();
        void turn_on(shared_ptr<LSource> ls);


        SceneManager(Field& field);
        ~SceneManager();
};