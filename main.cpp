#include "functions.h"
#include "image.h"
#include "2d_field.h"
#include <iostream>

int main() {

    // filter_select();

    Field field({300, 400});
    field.print_image();

    cout << "Add Circle or Rectangle? (c/r)" << endl;
    string answer;
    cin >> answer;
    if (answer == "c") {
        field.add_obstacle({field.getDimensions().height / 2, field.getDimensions().width / 2}, CIRCLE, 40, Color::RED);
        field.print_image();
    } else if (answer == "r") {
        field.add_obstacle({field.getDimensions().height / 2, field.getDimensions().width / 2 + 50}, RECTANGLE, 40, Color::BLUE);
        field.print_image();
    }

    return 0;
}

