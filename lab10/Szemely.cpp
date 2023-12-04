//
// Created by Alpar on 2023. 12. 03..
//

#include "Szemely.h"


Szemely::Szemely(const string &keresztNev, const string &vezetekNev, int szuletesiEv){
    this->szuletesiEv = szuletesiEv;
    this->keresztNev = keresztNev;
    this->vezetekNev = vezetekNev;
}

void Szemely::print(ostream &os) const {
    os << "Vezeteknev:" << this->vezetekNev << "\n";
    os << "Keresztnev:" << this->keresztNev << "\n";
    os << "Szuletesi ev:" << this->szuletesiEv << "\n";

}

ostream &operator<<(ostream &os, const Szemely &szemely) {
    szemely.print(os);
    return os;
}
