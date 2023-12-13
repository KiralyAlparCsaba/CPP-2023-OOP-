#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Settlement.h"
#include "SettlementStatistics.h"
#include "SettlementStatisticsImpl.h"

int main() {
    SettlementStatistics *statistics = new SettlementStatisticsImpl("C:\\Users\\Alpar\\Documents\\GitHub\\Cpp2023\\lab12\\telepulesek.csv");
    cout<< statistics->numSettlements() << endl;
    cout<< statistics->numCounties() << endl;
    cout<< statistics->numSettlementsByCounty("Alba");
    //cout<< ss.findSettlementsByCounty("Cluj");
    cout<< statistics->findSettlementsByNameAndCounty("Targu", "Mures");
    cout<< statistics->maxPopulation();
    cout<< statistics->minPopulation();
    //cout<< ss.findSettlementsByName("Iasi");






}