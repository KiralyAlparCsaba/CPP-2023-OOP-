#include <iostream>
#include "LIST.h"
#include "Stack.h"

int main() {

    List list1;
    for (int i = 1; i < 10; ++i) {
        list1.insertFirst(i);
        list1.print();

    }
    list1.removeFirst();
    list1.print();

    list1.remove(7,List::DeleteFlag::EQUAL);
    list1.print();

    cout<<list1.size()<<endl;
    cout<<list1.empty()<<endl;



    Stack stack;
    for (int i = 1; i < 10; ++i) {
        stack.push(i);
        cout<<stack.pop()<<endl;
    }
}
