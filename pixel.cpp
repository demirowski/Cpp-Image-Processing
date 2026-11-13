#include "pixel.h"
#include <iostream>

Pixel::Pixel(Coordinates cd) 
: red(0), green(0), blue(0), is_black(true), is_white(false), coordinates(cd)
{}

Pixel::Pixel() 
: red(0), green(0), blue(0), is_black(true), is_white(false)
{}

Pixel::~Pixel() {}

void Pixel::upload_rgb(unsigned char red, unsigned char green, unsigned char blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void Pixel::print_rgb() {
    std::cout << "Red: " << (double)this->red << std::endl
         << "Green: " << (double)this->green << std::endl
         << "Blue: " << (double)this->blue << std::endl;
}

void Pixel::add_to_rgb(int r, int g, int b) {
    
    if (r + (int)red > 255) {
        red = 255;
    } else if (r + (int)red < 0) {
        red = 0;
    } else {
        red += r;
    }

    if (g + (int)green > 255) {
        green = 255;
    } else if (g + (int)green < 0) {
        green = 0;
    } else {
        green += g;
    }

    if (b + (int)blue > 255) {
        blue = 255;
    } else if (b + (int)blue < 0) {
        blue = 0;
    } else {
        blue += b;
    }
}

void Pixel::factor_rgb(float r, float g, float b) {
    red *= r;
    green *= g;
    blue *= b;
}


unsigned char Pixel::getRed() {
    return red;
}

unsigned char Pixel::getGreen() {
    return green;
}

unsigned char Pixel::getBlue() {
    return blue;
}

void Pixel::set_black() {
    this->upload_rgb(0, 0, 0);
    this->is_black = true;
    this->is_white = false;
}

void Pixel::set_white() {
    this->upload_rgb(255, 255, 255);
    this->is_black = false;
    this->is_white = true;
}

bool Pixel::check_black() {
    return is_black ? true : false; 
}

bool Pixel::check_white() {
    return is_white ? true : false; 
}

bool Pixel::is_in(Obstacle& obs) {
    switch (obs.getShape()) {
        case CIRCLE:
        if (sqrt(pow(obs.getCoordinates().y - coordinates.y, 2) + pow(obs.getCoordinates().x - coordinates.x, 2)) <= obs.getRadius()) {
            return true;
        }
        break;
        case RECTANGLE:
        if (abs(coordinates.y - obs.getCoordinates().y) <= obs.getRadius() && abs(coordinates.x - obs.getCoordinates().x) <= obs.getRadius()) {
            return true;
        }
        break;
    }
    return false;
}

void Pixel::setCoordinates(int y, int x) {
    coordinates.y = y;
    coordinates.x = x;
}


