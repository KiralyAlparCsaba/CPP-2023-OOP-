//
// Created by Alpar on 2023. 09. 27
//

#include "functions.h"

int countBits(int number){

    int count = 0;
    while (number != 0) {
        number = number & (number - 1);
        count++;
    }
    return count;

}
bool setBit(int& number, int order) {
    if (order < 0 || order > 31) {
        return false; // Nem megfelelő sorszám
    }

    int mask = 1 << order;
    number |= mask; // Bit beállítása 1-re

    return true;
}

double mean(double array[], int numElements) {
    if (numElements <= 0) {
        return NAN;
    }

    double sum = 0.0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }

    return sum / numElements;
}
double stddev(double array[], int numElements) {
    if (numElements <= 0) {
        return NAN;
    }
