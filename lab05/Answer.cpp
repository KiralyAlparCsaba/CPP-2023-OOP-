//
// Created by Alpar on 2023. 10. 25..
//

#include "Answer.h"

Answer::Answer(const string &text) : text(text, correct = false) {}

const string &Answer::getText() const {
    return text;
}

bool Answer::isCorrect() const {
    return correct;
}

void Answer::setCorrect(bool correct) {
    Answer::correct = correct;
}
