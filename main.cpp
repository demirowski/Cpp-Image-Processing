#include "functions.h"
#include "image.h"
#include "2d_field.h"
#include "scene_manager.h"
#include <iostream>

int main() {

    // filter_select();

    Field field({300, 400});
    field.print_image();
    SceneManager manager(field);

    int field_h = field.getDimensions().height;
    int field_w = field.getDimensions().width;

    // adding obstacles
    // field.add_obstacle({field.getDimensions().height / 2, field.getDimensions().width / 2 + 50}, SQUARE, 40, Color::BLUE);
    field.add_obstacle({field_h / 2.0, field_w / 2.0}, CIRCLE, 40, Color::RED);
    
    // adding light source
    field.add_light_source({field_h / 2.0, field_w / 2.0 - 100}, Color::BLUE, 1.0);
    
    // turning all lights on
    manager.turn_on_all();
    field.print_image();

    return 0;
}

