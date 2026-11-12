#include "functions.h"
#include "image.h"
#include "2d_field.h"


int main() {

    // filter_select();

    Field field({300, 400});
    field.print_image("result.png");

    return 0;
}

