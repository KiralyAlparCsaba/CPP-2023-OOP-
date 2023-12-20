#include <iostream>
#include "SimpleTextGenerator.h"

int main() {

SimpleTextGenerator simpleTextGenerator;
simpleTextGenerator.trainFromFile("C:\\Users\\Alpar\\Documents\\GitHub\\Cpp2023\\lab13\\bible.txt");
cout << simpleTextGenerator.generate("now is", 100) << endl;
//simpleTextGenerator.printData();









}