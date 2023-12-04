#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"

using namespace std;

int main() {
   Szemely *sz1 = new Alkalmazott("Thomas","Eddison",1777,"sales");
   //sz1->print(cout);

   Szemely *sz2 = new Alkalmazott("Jhonny","Since",2001,"IT");
   //sz2->print(cout);

   cout << *sz2;

   Szemely *sz3 = new Manager("Thomas","Johnny",1757,"Manager");
   cout << *sz3;
}