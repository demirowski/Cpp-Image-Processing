#include "conversions.h"
#include "image.h"


int main() {

    Image image = download_into_array("demir.png");

    image.pixel_field[image.dimensions.height/2][image.dimensions.width/2].print_rgb();

    green_filter(image, 1.0f);

    print_from_array(image, "result.png");

    return 0;
}