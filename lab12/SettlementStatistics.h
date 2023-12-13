//
// Created by Alpar on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICS_H
#define CPP_2022_SETTLEMENTSTATISTICS_H

#include <vector>
#include "Settlement.h"

struct SettlementStatistics {
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const string& county) const = 0;
    virtual vector<Settlement> findSettlementsByCounty(
            const string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty(
            const string& name, const string& county) const = 0;
    virtual Settlement maxPopulation() const = 0;
    virtual Settlement minPopulation() const = 0;
    virtual vector<Settlement> findSettlementsByName(
            const string& name) = 0;
    };



#endif //CPP_2022_SETTLEMENTSTATISTICS_H
