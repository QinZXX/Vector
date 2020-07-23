#include "QRandom.h"

int getRandNum(int min, int max) {
    //srand(time(NULL));
    return (min + rand() % (max - min + 1));
}