//
// Created by Alpar on 2023. 10. 11..
//

#include <iostream>
#include "LIST.h"

List::List() {
    this->first = nullptr;
}

List::~List() {
    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;

    }



}

bool List::exists(int d) const {
    for (Node * n = first; n != nullptr; n = n->next) {
        if (n->value == d) {
            return true;
        }

    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return first == nullptr;
}

void List::insertFirst(int d) {
    first = new Node(d, this->first);
    nodeCounter++;

}

int List::removeFirst() {
    if(first == nullptr){
        throw runtime_error("List is empty");
    }
    Node * tmp = this->first;
    int value = tmp->value;
    this->first = this->first->next;
    delete tmp;
    return value;
}

void List::remove(int d, List::DeleteFlag df) {
    Node * prev = nullptr;
    for (Node * n = first; n != nullptr; n = n->next) {
                if ((n->value == d && df == List::DeleteFlag::EQUAL) || (n->value < d && df == List::DeleteFlag::LESS) || (n->value > d && df == List::DeleteFlag::GREATER)) {
                    if (prev == nullptr) {
                        removeFirst();
                        return;
                    }
                    prev->next = n->next;
                    delete n;
                    nodeCounter--;
                    return;

                }
                prev = n;
            }
        }

void List::print() const {
    for (Node * n = first; n != nullptr; n = n->next){
        if(n != first){
            cout<<", ";
        }
        cout << n->value;
    }
    cout<< endl;

}




