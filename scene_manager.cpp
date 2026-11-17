#include "scene_manager.h"

SceneManager::SceneManager(Field& field) 
: sources(field.getLights()), obstacles(field.getObstacles()), dimensions(field.getDimensions()), pixel_field(field.getPixelField())
{
}

SceneManager::~SceneManager() {}

void SceneManager::draw_ray_fake(Coordinates cd, double f) {

    for (int i = 0; i < dimensions.height; i++) {
        for (int j = 0; j < dimensions.width; j++) {
            int y = i - cd.y;
            int x = j - cd.x;

            double r = sqrt(x*x + y*y);
            // calculate how bright the light is on that pixel
            double brightness = 1 - (r/100.0);
            // std::cout << brightness << std::endl;
            if (brightness < epsilon) brightness = 0.0; 

            pixel_field[i][j].add_to_rgb(Color::LIGHT * brightness);
            
        }
    }
}

shared_ptr<Obstacle>& SceneManager::findShape(Vector2d cords) {
    for (auto& s : obstacles) {
        if (pixel_field[cords.y][cords.x].is_in(*s)) {
            return s;
        }
    }
}

double SceneManager::calculate_angle(shared_ptr<Obstacle>& obs) {
    Shapes shape = obs->getShape();
    Coordinates cd = obs->getCoordinates();

    switch(shape) {
        case CIRCLE:
            Coordinates circle_cords = obs->getCoordinates();
            Vector2d circleV = {circle_cords.y, circle_cords.x};
            double radius = obs->getRadius();
            double distance = distanceV()
        break;

        case SQUARE:

        break;
    }


}

void SceneManager::draw_ray(Coordinates cd, double angle, double strength) {

    double brightness = 1;
    double radiant = angle * (pi / 180.0);
    double sin_val = sin(radiant);
    double cos_val = cos(radiant);
    // true location of the ray, regardless of the rounding
    Vector2d ray_vector = {cd.y, cd.x};

    while (brightness > 0) {

        ray_vector = ray_vector + Vector2d{sin_val, cos_val};

        Vector2d rounded_vector = {floor(ray_vector.y), floor(ray_vector.x)};

        if (rounded_vector.x < 0 || rounded_vector.x >= dimensions.width || rounded_vector.y < 0 || rounded_vector.y >= dimensions.height) {
            return;
        }

        for (auto& s : obstacles) {
            if (pixel_field[rounded_vector.y][rounded_vector.x].get_OnObstacle()) {

                double new_strength = strength * 0.6;
                double new_angle = calculate_angle(findShape(rounded_vector));
                draw_ray(Coordinates{rounded_vector.y, rounded_vector.x}, new_angle, new_strength);
                return;
            }
        }
        

        pixel_field[rounded_vector.y][rounded_vector.x].add_to_rgb(Color::LIGHT * strength * brightness);

        brightness *= 0.987;
        if (brightness < epsilon) brightness = 0;
    }

}

void SceneManager::turn_on(shared_ptr<LSource> ls) {
    for (int f = 0; f < 360; f++) {
        draw_ray(ls->getCoordinates(), f, ls->getStrength());
    }
}


void SceneManager::turn_on_all() {
    // cout << sources.size() << endl;
    for (int i = 0; i < sources.size(); i++) {
        turn_on(sources[i]);
    }
}

