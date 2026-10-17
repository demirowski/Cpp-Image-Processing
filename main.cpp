#include "conversions.h"
#include "image.h"


int main() {

    string path_name;
    int answer;
    bool check = true;
    Image image;
    
    do {
        cout << "Type the name of the image: ";
        cin >> path_name;
        image = download_into_array(path_name, check);
    } while (!check);
    

    cout << "What filter do you want to apply?" << endl
         << "1. Red Filter" << endl
         << "2. Green Filter" << endl
         << "3. BLue Filter" << endl
         << "4. Gray Filter" << endl
         << "5. Pure Black & White" << endl
         << "Type (1/2/3/4/5): ";
    cin >> answer;

    switch (answer) {
        case 1:
        red_filter(image, 1.0f);
        break;
        case 2:
        green_filter(image, 1.0f);
        break;
        case 3:
        blue_filter(image, 1.0f);
        break;
        case 4:
        gray_filter(image);
        break;
        case 5:
        pure_black_n_white(image);
        break;
        default:
        cout << "That's not one of the options." << endl;
        break;
    }

    print_from_array(image, "result.png");

    return 0;
}