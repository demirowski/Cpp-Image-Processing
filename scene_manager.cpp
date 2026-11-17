#include "scene_manager.h"

SceneManager::SceneManager(Field& field) 
: sources(field.getLights()), obstacles(field.getObstacles()), dimensions(field.getDimensions()), pixel_field(field.getPixelField())
{
}

SceneManager::~SceneManager() {}

void SceneManager::draw_ray(Coordinates cd, double f) {

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

void SceneManager::turn_on(shared_ptr<LSource> ls) {
    draw_ray(ls->getCoordinates(), 0.0f);
}


void SceneManager::turn_on_all() {
    // cout << sources.size() << endl;
    for (int i = 0; i < sources.size(); i++) {
        turn_on(sources[i]);
    }
}

