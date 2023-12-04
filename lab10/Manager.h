//
// Created by Alpar on 2023. 12. 03..
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include<iostream>
#include <string>
#include <vector>
#include "Alkalmazott.h"

using namespace std;


class Manager : public Alkalmazott {
private:
    vector<Alkalmazott> beosztottak;
public:
    Manager(const string &keresztNev, const string &vezetekNev, int szuletesiEv, const string &munkakor);
    void addBeosztott( Alkalmazott beosztott);
    void deleteBeosztott(int id);
    int getBeosztottakNr() const;
    virtual void print(ostream &os) const;

};
static const string MANAGER_MUNKAKOR = "Manager";

#endif //CPP_2022_MANAGER_H
