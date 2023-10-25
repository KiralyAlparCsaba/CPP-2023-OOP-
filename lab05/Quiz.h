//
// Created by Alpar on 2023. 10. 25..
//

#ifndef CPP_2022_QUIZ_H
#define CPP_2022_QUIZ_H

using namespace std;
#include<string>
#include "Question.h"

class Quiz {
private:
    const string text;
    vector<Question> questions;
public:
     Quiz(const string &text, const vector<Question> &questions);

    explicit Quiz(const string &text);

    const string &getText() const;

    vector<Question> &getQuestions();

    void readFromFile(const string Filename);

};


#endif //CPP_2022_QUIZ_H
