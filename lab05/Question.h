//
// Created by Alpar on 2023. 10. 25..
//

#ifndef CPP_2022_QUESTION_H
#define CPP_2022_QUESTION_H
using namespace std;
#include<string>
#include <vector>
#include "Answer.h"

class Question {
private:
    const string text;
    vector<Answer> answers;
public:
    explicit Question(const string &text);
    Question(const string &text, const vector<Answer> &answers);
    const string &getText() const;
    vector<Answer> &getAnswers();


};



#endif //CPP_2022_QUESTION_H
