//
// Created by Alpar on 2023. 12. 13..
//

#include "Settlement.h"

Settlement::Settlement(const string &name, const string &county, long long population) : name(name), county(county),
                                                                                   population(population) {}

const string &Settlement::getName() const {
    return name;
}

const string &Settlement::getCounty() const {
    return county;
}

long long Settlement::getPopulation() const {
    return population;
}

void Settlement::setName(const string &name) {
    Settlement::name = name;
}

void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

ostream &operator<<(ostream &os, const Settlement &settlement) {
    os << "name: " << settlement.name << " county: " << settlement.county << " population: " << settlement.population;
    return os;
}
