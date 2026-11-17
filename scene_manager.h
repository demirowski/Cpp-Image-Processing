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

        shared_ptr<Obstacle>& findShape(Vector2d cords);
        double SceneManager::calculate_angle(shared_ptr<Obstacle>& obs);

        void draw_ray_fake(Coordinates cd, double f);
        void draw_ray(Coordinates cd, double angle, double strength);
        void turn_on_all();
        void turn_on(shared_ptr<LSource> ls);


        SceneManager(Field& field);
        ~SceneManager();
};