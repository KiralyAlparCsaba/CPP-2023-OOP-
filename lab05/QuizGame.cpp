//
// Created by Alpar on 2023. 10. 25..
//

#include <random>
#include "QuizGame.h"



QuizGame::QuizGame(string quizName, string FileName): quiz(quizName) {
    quiz.readFromFile(FileName);
}

void QuizGame::startGame() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, quiz.getQuestions().size());
    vector<int> order;
    int M = quiz.getQuestions().size();
    for (int i = 0; i < M; ++i) {
        order.push_back(i);
    }
    auto first = order.begin();
    auto last = order.back();
    for (auto i = (last - first) - 1; i > 0; --i){
        swap(first[i], first[dist(mt)]);
    }


    for (int i = 0; i < order.size(); ++i) {
        cout << i << "->" << order[i] << endl;
    }
    rightAnswer = 0;
    for (int i = 0; i < order.size(); ++i) {
        Question q = quiz.getQuestions()[order[i]];
        cout << q.getText() << endl;

        for (const Answer& a : q.getAnswers()) {
            cout << "\t" << a.getText() << endl;
        }
        cout << "Adja meg a helyes valaszt! :";
        int n;
        cin >> n;
        if(q.getAnswers()[n].isCorrect()){
            rightAnswer ++;
        }

    }
    cout << "helyes valaszok szama: " << rightAnswer;
}
