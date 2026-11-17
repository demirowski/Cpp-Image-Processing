#include "scene_manager.h"

#define STB_IMAGE_WRITE_STATIC
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "libraries/stb_image.h"
#include "libraries/stb_image_write.h"


SceneManager::SceneManager(Field& field) 
: sources(field.getLights()), obstacles(field.getObstacles()), dimensions(field.getDimensions()), pixel_field(field.getPixelField()), field(field)
{
}

SceneManager::~SceneManager() {}

void SceneManager::draw_ray_fake(Vector2d cd, double f) {

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

shared_ptr<Obstacle> SceneManager::findShape(Vector2d cords) {
    for (auto& s : obstacles) {
        if (pixel_field[cords.y][cords.x].is_in(*s)) {
            return s;
        }
    }
    return nullptr;
}

Vector2d SceneManager::calculate_direction(Vector2d old_direction, Vector2d collision_point, shared_ptr<Obstacle>& obs) {
    Shapes shape = obs->getShape();
    Vector2d ref_vector;

    switch(shape) {
        case CIRCLE: {

            Vector2d surface_normal = (collision_point - obs->getCoordinates()) / obs->getRadius();
            double dot = dotProduct(old_direction, surface_normal);
            
            ref_vector = old_direction - 2 * dot * surface_normal;
        }
        break;

        case SQUARE: {

            return Vector2d{0.0, 0.0};

        }
        break;
    }

    return ref_vector;


}

void SceneManager::draw_ray(Vector2d cd, Vector2d direction_vector, double strength, int depth = 0, Color cl = Color::LIGHT) {

    if (depth > 10) return; // recommended from ai to end the recursive call chain

    double brightness = 1;

    // true location of the ray, regardless of the rounding
    Vector2d ray_vector = {cd.y, cd.x};


    while (brightness > 0) {

        ray_vector = ray_vector + direction_vector;

        Vector2d rounded_vector = {round(ray_vector.y), round(ray_vector.x)};

        if (rounded_vector.x < 0 || rounded_vector.x >= dimensions.width || rounded_vector.y < 0 || rounded_vector.y >= dimensions.height) {
            return;
        }

        for (auto& s : obstacles) {
            if (pixel_field[rounded_vector.y][rounded_vector.x].get_OnObstacle()) {

                shared_ptr<Obstacle> hit_obstacle = findShape(rounded_vector);

                if (hit_obstacle != nullptr) {
                    double new_strength = strength * 0.6;
                    Vector2d new_direction = calculate_direction(direction_vector, ray_vector, hit_obstacle);
                    draw_ray(rounded_vector, new_direction, new_strength, depth + 1, cl);
                    return;
                }
                
            }
        }
        

        pixel_field[rounded_vector.y][rounded_vector.x].add_to_rgb(cl * strength * brightness);

        brightness *= 0.986;
        if (brightness < epsilon) brightness = 0;
    }

}

void SceneManager::turn_on(shared_ptr<LSource> ls) {
    ls->turnON();
}

void SceneManager::updateScene() {
    for (auto &ls : sources) {
        if (ls->getStatus()) {
            for (double f = 0; f < 360; f = f + 1) {
                double radiant = f * (pi / 180.0);
                double sin_val = sin(radiant);
                double cos_val = cos(radiant);
                Vector2d direction_vector = {sin_val, cos_val};
                draw_ray(ls->getCoordinates(), direction_vector, ls->getStrength(), 0, ls->getColor());
            }
        }
    }
}

void SceneManager::resetScene() {
    for (int i = 0; i < dimensions.height; i++) {
        for (int j = 0; j < dimensions.width; j++) {
            pixel_field[i][j].set_rgb(field.getColor());
        }
    }
}


void SceneManager::turn_on_all() {
    // cout << sources.size() << endl;
    for (int i = 0; i < sources.size(); i++) {
        turn_on(sources[i]);
    }
}

void SceneManager::print_image(string name) {
    int height = dimensions.height;
    int width = dimensions.width;
    int channels = 3;

    vector<unsigned char> data(height * width * channels);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            int index = ((i * width) + j) * channels;

            data[index    ] = pixel_field[i][j].getRed();
            data[index + 1] = pixel_field[i][j].getGreen();
            data[index + 2] = pixel_field[i][j].getBlue();
        }
    }


    stbi_write_png(name.c_str(), width, height, channels, data.data(), width * channels);
}



