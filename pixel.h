#ifndef PIXEL_H
#define PIXEL_H

#include "structs.h"
#include "object.h"

class Pixel {

    private:
        unsigned char red, green, blue;
        bool is_black, is_white;
        Coordinates coordinates;

    public:
        void upload_rgb(unsigned char red, unsigned char green, unsigned char blue);
        void add_to_rgb(uint8_t r, uint8_t g, uint8_t b);
        void add_to_rgb(Color cl);

        void set_rgb(Color cl);

        void factor_rgb(float r, float g, float b);
        void print_rgb();

        unsigned char getRed();
        unsigned char getGreen();
        unsigned char getBlue();

        void set_black(); // sets singular pixel to pure black
        void set_white(); // sets singular pixel to pure white

        bool check_black();
        bool check_white();

        bool is_in(Object& shape);
        void setCoordinates(int y, int x);

        Pixel(Coordinates cd);
        Pixel();
        ~Pixel();
};

#endif