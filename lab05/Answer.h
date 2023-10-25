//
// Created by Alpar on 2023. 10. 25..
//

#ifndef CPP_2022_ANSWER_H
#define CPP_2022_ANSWER_H

using namespace std;
#include<string>
#include<iostream>

class Answer {
private:
    const string text;
    bool correct;


public:
    explicit Answer(const string &text);
    const string &getText() const;
    bool isCorrect() const;
    void setCorrect(bool correct);

};


#endif //CPP_2022_ANSWER_H
