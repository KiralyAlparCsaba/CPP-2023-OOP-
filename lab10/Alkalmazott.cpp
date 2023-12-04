//
// Created by Alpar on 2023. 12. 03..
//

#include "Alkalmazott.h"

int Alkalmazott::counter = 1;

void Alkalmazott::print(ostream &os) const {
    Szemely::print(os);
    os << "Munkakor:" << this->munkakor << "\n";
    os << "ID:" << this->id << "\n";
}

Alkalmazott::Alkalmazott(const string &keresztNev, const string &vezetekNev, int szuletesiEv, const string &munkakor)
: Szemely(vezetekNev, keresztNev, szuletesiEv) {
    this->munkakor = munkakor;
    this->id = counter;
    counter += 1;

}

int Alkalmazott::getID() {
    return this->id;
}

