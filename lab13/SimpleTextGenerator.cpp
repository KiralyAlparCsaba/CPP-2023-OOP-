//
// Created by Alpar on 2023. 12. 20..
//

#include<iostream>
#include <sstream>
#include <fstream>
#include<algorithm>
#include <random>
#include "SimpleTextGenerator.h"

//Now is not the time for sleep, now is
//the time for party!
void SimpleTextGenerator::trainFromText(string trainingText) {
    for (char &c: trainingText) {
        c = tolower(c);
        if (c < 'a' || c > 'z') {
            c = ' ';
        }
    }
    stringstream ss(trainingText);
    string word;
    string prev1;
    string prev2;
    ss >> prev1;
    ss >> prev2;

    while (ss >> word) {
        string key = prev1 + ' ' + prev2;
        if (data.contains(key)) {
            vector<string> &words = data.at(key);
            auto it = std::find(data.at(key).begin(), data.at(key).end(), word);
            if (it == words.end()) {
                words.push_back(word);
            }
        } else {
            vector<string> words{word};
            data.insert(pair(key, words));
        }
        prev1 = prev2;
        prev2 = word;
    }

}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream f(filename);
    if(!f){
        throw runtime_error("File not found");
    }
    string line;
    while(getline(f, line)){
        trainFromText(line);
    }

}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    random_device rd;
    mt19937 mt(rd());
    string prev1;
    string prev2;
    stringstream ss(startWords);
    ss >> prev1;
    ss >> prev2;
    for (int i = 0; i < numWords; ++i) {
        string key = prev1 + ' ' + prev2;
        if(!data.contains(key)){
            break;
        }
        const vector<string> &words = data.at(key);
        if(words.empty()){
            break;
        }

        uniform_int_distribution<int> dist(0, words.size() -1);
        prev1 = prev2;
        prev2 = words.at(dist(mt));


        startWords.append(" ").append(prev2);

    }
    return startWords;
}

void SimpleTextGenerator::printData() const {
    for (const auto& pair : data) {
        std::cout << "Key: " << pair.first << std::endl;
        std::cout << "Values: ";
        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

}
