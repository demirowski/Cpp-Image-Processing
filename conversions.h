#pragma once

#include <string>
#include <vector>
#include "pixel.h"
#include "image.h"
#include <iostream>

using namespace std;

Image download_into_array(string path_name, bool &check);

void print_from_array(Image &image, string name);

void red_filter(Image &image, float rate);
void green_filter(Image &image, float rate);
void blue_filter(Image &image, float rate);

void gray_filter(Image &image);
void pure_black_n_white(Image &image);