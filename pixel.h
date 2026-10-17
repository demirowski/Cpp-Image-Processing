#ifndef PIXEL_H
#define PIXEL_H

class Pixel {

    private:
        unsigned char red, green, blue;
        bool is_black, is_white;

    public:
        void upload_rgb(unsigned char red, unsigned char green, unsigned char blue);
        void add_to_rgb(int r, int g, int b);
        void factor_rgb(float r, float g, float b);
        void print_rgb();

        unsigned char getRed();
        unsigned char getGreen();
        unsigned char getBlue();

        void set_black();
        void set_white();

        bool check_black();
        bool check_white();
};

#endif