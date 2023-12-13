//
// Created by Alpar on 2023. 12. 13..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICSIMPL_H
#define CPP_2022_SETTLEMENTSTATISTICSIMPL_H


#include <map>
#include "SettlementStatistics.h"

class SettlementStatisticsImpl : public SettlementStatistics {
private:
    multimap<string,Settlement> settlements;
public:
    explicit SettlementStatisticsImpl(const string &filename);

    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    vector<Settlement> findSettlementsByCounty(const string &county) const override;

    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;

    Settlement maxPopulation() const override;

    Settlement minPopulation() const override;

    vector<Settlement> findSettlementsByName(const string &name) override;


};


#endif //CPP_2022_SETTLEMENTSTATISTICSIMPL_H
