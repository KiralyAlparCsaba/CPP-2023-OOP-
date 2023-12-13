//
// Created by Alpar on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENT_H
#define CPP_2022_SETTLEMENT_H

using namespace std;
#include<string>
#include <ostream>


class Settlement {
    string name = "";
    string county = "";
    long long population = 0;
// constructor, getters, setters, inserter operator
public:
    Settlement(const string &name, const string &county, long long population);

    const string &getName() const;

    const string &getCounty() const;

    long long getPopulation() const;

    void setName(const string &name);

    void setCounty(const string &county);

    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const Settlement &settlement);
};

#endif //CPP_2022_SETTLEMENT_H
