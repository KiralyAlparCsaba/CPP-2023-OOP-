//
// Created by Alpar on 2023. 12. 03..
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include <iostream>
#include <string>
#include "Szemely.h"

using namespace std;



class Alkalmazott : public Szemely{
protected:
    string munkakor;
    int id;
    static int counter;
public:
    explicit Alkalmazott(const string &keresztNev, const string &vezetekNev, int szuletesiEv,const string &munkakor);
    virtual void print(ostream &os)const override;
    int getID();

    const string &getMunkakor() const;

};



#endif //CPP_2022_ALKALMAZOTT_H
