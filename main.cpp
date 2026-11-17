#include "2d_field.h"
#include "scene_manager.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {

    // filter_select();

    Field field(Color::BLACK, {300, 400});
    SceneManager manager(field);
    manager.print_image();

    int field_h = field.getDimensions().height;
    int field_w = field.getDimensions().width;

    field.add_obstacle({field_h / 2.0 - 60, field_w / 2.0}, CIRCLE, 30, Color::RED);
    field.add_obstacle({field_h / 2.0 + 60, field_w / 2.0 + 20}, CIRCLE, 35, Color::BLUE);
    
    // adding light source
    field.add_light_source({field_h / 2.0, field_w / 2.0 - 100}, Color::LIGHT, 0.7);
    field.add_light_source({field_h / 2.0 -100, field_w / 2.0 + 140}, Color::LIGHT_BLUE, 0.7);
    
    // turning all lights on
    manager.turn_on_all();
    manager.updateScene();
    manager.print_image();


    return 0;
}

