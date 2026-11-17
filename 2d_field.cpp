#include "2d_field.h"
#include "libraries/stb_image.h"
#include "libraries/stb_image_write.h"

Field::Field(Color cl, Dimensions dm) 
: bg_color(cl), dimensions(dm)
{
    pixel_field.resize(dm.height);
    for (int i = 0; i < dm.height; ++i) {
        pixel_field[i].resize(dm.width);
        for (int j = 0; j < dm.width; ++j) {
            pixel_field[i][j].setCoordinates(i, j);
            pixel_field[i][j].set_rgb(bg_color);
        }
    }
}

Field::Field(Dimensions dm) 
: dimensions(dm)
{
    pixel_field.resize(dm.height);
    for(int i = 0; i < dm.height; ++i) {
        pixel_field[i].resize(dm.width);
        for (int j = 0; j < dm.width; ++j) {
            pixel_field[i][j].setCoordinates(i, j);
        }
    }
}

Field::~Field()
{}

void Field::add_obstacle(Vector2d cd, Shapes sp, int radius, Color cl) {
    Obstacle obs(cd, sp, radius, cl);
    obstacles.push_back(make_shared<Obstacle>(obs));

    for (int i = 0; i < dimensions.height; ++i) {
        for (int j = 0; j < dimensions.width; ++j) {
            if (pixel_field[i][j].is_in(obs)) {
                pixel_field[i][j].set_rgb(obs.getColor());
                pixel_field[i][j].set_on_obstacle();
            }
        }
    }
}

void Field::move_lsource(int place, Vector2d displacement) {
    
}

void Field::add_light_source(Vector2d cd, Color cl, float strength) {
    LSource ls(cd, CIRCLE, cl, strength);
    sources.push_back(make_shared<LSource>(ls));

    for (int i = 0; i < dimensions.height; ++i) {
        for (int j = 0; j < dimensions.width; ++j) {
            if (pixel_field[i][j].is_in(ls)) {
                pixel_field[i][j].set_rgb(ls.getColor());
            }
        }
    }
}

void Field::move_obstacle(int place, Vector2d displacement) {

    Vector2d cords = obstacles[place]->getCoordinates();
    double radius = obstacles[place]->getRadius();
    for (int i = cords.y - radius; i < cords.y + radius; i++) {
        for (int j = cords.x - radius; j < cords.x + radius; j++) {
            pixel_field[i][j].set_off_obstacle();
            pixel_field[i][j].set_rgb(bg_color);
            Vector2d new_vector = Vector2d{(double)i, (double)j} + displacement;
            pixel_field[new_vector.y][new_vector.x].set_on_obstacle(); 
            pixel_field[new_vector.y][new_vector.x].set_rgb(obstacles[place]->getColor()); 
        }
    }

    obstacles[place]->moveCoordinates(displacement);

}


Dimensions Field::getDimensions() {
    return dimensions;
}

vector<shared_ptr<LSource>>& Field::getLights() {
    return sources;
}

vector<shared_ptr<Obstacle>>& Field::getObstacles() {
    return obstacles;
}

vector<vector<Pixel>>& Field::getPixelField() {
    return pixel_field;
}

Color Field::getColor() {
    return bg_color;
}