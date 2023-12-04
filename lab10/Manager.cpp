//
// Created by Alpar on 2023. 12. 03..
//

#include <algorithm>
#include "Manager.h"

Manager::Manager(const string &keresztNev, const string &vezetekNev, int szuletesiEv, const string &munkakor)
        : Alkalmazott(keresztNev, vezetekNev, szuletesiEv, munkakor) {

}

void Manager::addBeosztott(Alkalmazott beosztott) {
    this->beosztottak.push_back(beosztott);
}

void Manager::deleteBeosztott(int id) {
    auto item = find_if(this->beosztottak.begin(), this->beosztottak.end(), [id](Alkalmazott item) {
        return item.getID() == id;
    });
    if (item != this->beosztottak.end()) {
        this->beosztottak.erase(item);
    }

}

int Manager::getBeosztottakNr() const {
    return this->beosztottak.size();
}

void Manager::print(ostream &os) const {
    os << "Manager: " << this->id << " " << this->vezetekNev << " " << this->keresztNev << " " << this->szuletesiEv << " ";
    for ( auto b: this->beosztottak) {
        b.print(os);
    }
}
