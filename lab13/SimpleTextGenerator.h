//
// Created by Alpar on 2023. 12. 20..
//

#ifndef CPP_2022_SIMPLETEXTGENERATOR_H
#define CPP_2022_SIMPLETEXTGENERATOR_H

#include <string>
#include <vector>
#include <map>
#include "TextGenerator.h"

using namespace std;

class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};


#endif //CPP_2022_SIMPLETEXTGENERATOR_H
