//
// Created by Alpar on 2023. 10. 25..
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "Quiz.h"

Quiz::Quiz(const string &text, const vector<Question> &questions) : text(text), questions(questions) {}

Quiz::Quiz(const string &text) : text(text) {}

const string &Quiz::getText() const {
    return text;
}

 vector<Question> &Quiz::getQuestions()  {
    return questions;
}

void Quiz::readFromFile(const string Filename) {
    ifstream f(Filename);
    string line;
    if(!f){
        throw runtime_error("nem sikerult megnyitni a filet");
    }
    while(getline(f, line)){
        if(line[0] == 'Q' && line[1] == ' '){
            questions.emplace_back(line.substr(2));
            continue;
        }
        if(line[0] == 'A' && line[1] == ' '){
            questions.back().getAnswers().emplace_back(line.substr(2));
            continue;
        }
        stringstream s(line);
        while(1){
            int n;
            s >> n;
            if(!s) break;
            questions.back().getAnswers()[n-1].setCorrect(true);
        }
    }

}
/*void Quiz::readFromFile(const string Filename) {
    ifstream f(Filename);
    string line;
    if(!f){
        throw runtime_error("nem sikerult megnyitni a filet");
    }

    bool foundQuestion = false;

    while(getline(f, line)){
        if(line[0] == 'Q' && line[1] == ' '){
            questions.emplace_back(line.substr(2));
            foundQuestion = true;
            continue;
        }
        if(line[0] == 'A' && line[1] == ' '){
            questions.back().getAnswers().emplace_back(line.substr(2));
            continue;
        }
        stringstream s(line);
        while(1){
            int n;
            s >> n;
            if(!s) break;
            questions.back().getAnswers()[n-1].setCorrect(true);
        }
    }

    if (!foundQuestion) {
        throw runtime_error("nem talalt kerdest a fileban");
    }
}*/