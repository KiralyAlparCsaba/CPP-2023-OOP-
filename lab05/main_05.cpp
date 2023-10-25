#include <iostream>
#include "Quiz.h"



int main() {

    Quiz quiz("Quiz");
    quiz.readFromFile("C:\\Users\\Alpar\\Documents\\GitHub\\Cpp2023\\lab05\\bemenet.txt"); //azert raktam igy a file utat mert maskepp nem kapta meg valamiert ¯\_(ツ)_/¯
    for(Question q : quiz.getQuestions()){
        cout << q.getText() << endl;
        for(Answer a : q.getAnswers()){
            cout << "\t" << a.getText() << endl;
        }
    }


}