#include <iostream>
#include "image.h"
#include "Volna.h"
#include "Drawer.h"
using namespace std;

int main() {
    Image img;
    if (!img.loadImage("lab.bmp")) {
        cout << "Не удалось открыть BMP" << endl;
        return -1;
    }

    Volna volna;
    volna.findPath(img);

    if (!volna.hasPath()) {
        cout << "Путь не найден" << endl;
        return -1;
    }

    Drawer drawer;
    drawer.drawPath(img, volna);
    drawer.show();
    drawer.save("result.bmp");

    return 0;
}
