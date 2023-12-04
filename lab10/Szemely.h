//
// Created by Alpar on 2023. 12. 03..
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H


#include <iostream>
#include <string>

using namespace std;


class Szemely {

protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;
public:
    Szemely(const string &keresztNev, const string &vezetekNev, int szuletesiEv);

    virtual void print(ostream &os) const;

};

ostream& operator<<(std::ostream &os, const Szemely &szemely);


#endif //CPP_2022_SZEMELY_H
