#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

using namespace std;

int main() {
   Szemely *sz1 = new Alkalmazott("Thomas","Eddison",1777,"sales");
   //sz1->print(cout);

   Szemely *sz2 = new Alkalmazott("Jhonny","Since",2001,"IT");
   //sz2->print(cout);

   cout << *sz2;

   Szemely *sz3 = new Manager("Thomas","Johnny",1757,"Manager");
   cout << *sz3;

    Ceg company("aCompany");

    Alkalmazott al1 ("Mary", "Doe", 1950, "IT");
    Alkalmazott al2 ("John", "Smith", 1980, "IT");
    Alkalmazott al3 ("Ezekiel", "Johnson", 1970, "IT");
    Alkalmazott al4 ("Jani", "Williams", 1990, "IT");
    Alkalmazott al5 ("Miklos", "Brown", 1990, "IT");

    Manager al6 ("Wilson", "Jones", 1995,"manager");
    Alkalmazott al7 ("Olga", "Davis", 1990, "IT");
    Manager al8 ("Olivia", "Miller", 1995,"manager");
    Manager al9 ("Daniel", "Wilson", 1995,"manager");
    Alkalmazott al10 ("Sophia", "Taylor", 1999, "IT");



    company.addNewEmployee(&al1);
    company.addNewEmployee(&al2);
    company.addNewEmployee(&al3);
    company.addNewEmployee(&al4);
    company.addNewEmployee(&al5);
    company.addNewEmployee(&al6);
    company.addNewEmployee(&al7);
    company.addNewEmployee(&al8);
    company.addNewEmployee(&al9);
    company.addNewEmployee(&al10);

    company.printAllEmployees();

    company.assignEmployeeToManager(al6, al1);
    company.assignEmployeeToManager(al6, al3);
    company.assignEmployeeToManager(al6, al5);

    company.assignEmployeeToManager(al8, al10);
    company.assignEmployeeToManager(al8, al7);

    company.assignEmployeeToManager(al9, al4);
    company.assignEmployeeToManager(al9, al2);

    company.printOnlyManagers();

   
    company.detachEmployeeFromManager(al6, al5);
    company.assignEmployeeToManager(al9, al5);
    company.printOnlyManagers();

    return 0;
}