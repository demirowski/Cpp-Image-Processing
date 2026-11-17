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

    cout << "Add Circle or Rectangle or Light Source? (c/r/l)" << endl;
    string answer;
    cin >> answer;
    if (answer == "c") {
        field.add_obstacle({field.getDimensions().height / 2, field.getDimensions().width / 2}, CIRCLE, 40, Color::RED);
        
    } else if (answer == "r") {
        field.add_obstacle({field.getDimensions().height / 2, field.getDimensions().width / 2 + 50}, RECTANGLE, 40, Color::BLUE);
        
    } else if (answer == "l") {
        field.add_light_source({field.getDimensions().height / 2, field.getDimensions().width / 2 - 100}, Color::BLUE, 0.5);

    }
    manager.turn_on_all();
    field.print_image();

    return 0;
}

