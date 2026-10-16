#include "conversions.h"

#define STB_IMAGE_IMPLEMENTATION
#include "libraries/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "libraries/stb_image_write.h"

Image download_into_array(string path_name) {

    int width, height, channels;

    unsigned char* img = stbi_load(path_name.c_str(), &width, &height, &channels, 3);

    channels = 3;

    if (img == nullptr) {
        cout << "Download FAILED!" << endl;
        return Image({}, {0,0}, 0);
    }

    vector<vector<Pixel>> field(height, vector<Pixel>(width));

    for (int i = 0; i < width * height; i++) {
        int i2 = i * channels;

        field[i / width][i % width].upload_rgb(img[i2], img[i2 + 1], img[i2 + 2]);

    }

    stbi_image_free(img);

    Dimensions dims = {height, width};

    return Image(field, dims, channels);
}

void print_from_array(Image &image, string name) {

    int height = image.dimensions.height;
    int width = image.dimensions.width;
    int channels = image.channel_amount;

    vector<unsigned char> data(height * width * channels);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            int index = ((i * width) + j) * channels;

            data[index    ] = image.pixel_field[i][j].getRed();
            data[index + 1] = image.pixel_field[i][j].getGreen();
            data[index + 2] = image.pixel_field[i][j].getBlue();
        }
    }


    stbi_write_png(name.c_str(), width, height, channels, data.data(), width * channels);
}


void red_filter(Image &image, float rate) {

    if (rate > 1) {
        rate = 1;
    } else if (rate < 0) {
        rate = 0;
    }

    for (int i = 0; i < image.dimensions.height; i++) {
        for (int j = 0; j < image.dimensions.width; j++) {
            image.pixel_field[i][j].update_rgb(20 * rate, -50 * rate, -50 * rate);
        }
    }
}

void green_filter(Image &image, float rate) {

    if (rate > 1) {
        rate = 1;
    } else if (rate < 0) {
        rate = 0;
    }

    for (int i = 0; i < image.dimensions.height; i++) {
        for (int j = 0; j < image.dimensions.width; j++) {
            image.pixel_field[i][j].update_rgb(-50 * rate, 20 * rate, -50 * rate);
        }
    }
}

void blue_filter(Image &image, float rate) {

    if (rate > 1) {
        rate = 1;
    } else if (rate < 0) {
        rate = 0;
    }

    for (int i = 0; i < image.dimensions.height; i++) {
        for (int j = 0; j < image.dimensions.width; j++) {
            image.pixel_field[i][j].update_rgb(-50 * rate, -50 * rate, 20 * rate);
        }
    }
}
