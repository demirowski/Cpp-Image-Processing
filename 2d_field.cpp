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

void Field::add_obstacle(Coordinates cd, Shapes sp, int radius, Color cl) {
    Obstacle obs(cd, sp, radius, cl);
    obstacles.push_back(obs);

    for (int i = 0; i < dimensions.height; ++i) {
        for (int j = 0; j < dimensions.width; ++j) {
            if (pixel_field[i][j].is_in(obs)) {
                pixel_field[i][j].add_to_rgb(255, 0, 0);
            }
        }
    }

}




void Field::print_image(string name) {

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

Dimensions Field::getDimensions() {
    return dimensions;
}