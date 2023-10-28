//
// Created by Alpar on 2023. 10. 25..
//

#ifndef CPP_2022_QUIZGAME_H
#define CPP_2022_QUIZGAME_H


#include "Quiz.h"

class QuizGame {
private:
    Quiz quiz;
    int rightAnswer;
public:
    explicit QuizGame(string quizName, string FileName);
    void startGame();
};


#endif //CPP_2022_QUIZGAME_H
