#ifndef PIXEL_H
#define PIXEL_H

class Pixel {

    private:
        unsigned char red, green, blue;

    public:
        void upload_rgb(unsigned char red, unsigned char green, unsigned char blue);
        void update_rgb(int r, int g, int b);
        void print_rgb();

        unsigned char getRed();
        unsigned char getGreen();
        unsigned char getBlue();
};

#endif