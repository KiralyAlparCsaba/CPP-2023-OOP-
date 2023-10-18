//
// Created by Alpar on 2023. 10. 11...
//

#include "Stack.h"

void Stack::push(int e) {
    list.insertFirst(e);

}

int Stack::pop() {
    return list.removeFirst();
}

bool Stack::isEmpty() const {
    return list.empty();
}

Stack::Stack() {

}




