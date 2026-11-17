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
        Field& field;


    public:

        shared_ptr<Obstacle> findShape(Vector2d cords);
        Vector2d calculate_direction(Vector2d old_direction, Vector2d old_base, shared_ptr<Obstacle>& obs);

        void draw_ray_fake(Vector2d cd, double f);
        void draw_ray(Vector2d cd, Vector2d direction, double strength, int depth, Color cl);
        void turn_on_all();
        void turn_on(shared_ptr<LSource> ls);

        void updateScene();
        void resetScene();
        void print_image(string name = "result.png");


        SceneManager(Field& field);
        ~SceneManager();
};