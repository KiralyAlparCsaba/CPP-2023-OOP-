//
// Created by Alpar on 2023. 12. 13..
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "SettlementStatisticsImpl.h"

int SettlementStatisticsImpl::numSettlements() const {
    return this->settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    string temp = "";
    int result = 0;
    for (auto &[key, value] : this->settlements) {
        if (temp != key) {
            result ++;
            temp = key;
        }
    }
    return result;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return this->settlements.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;
    for(auto &[key, value] : this->settlements){
        if(key == county){
            result.push_back(value);
        }
    }
    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for(auto &[key, value] : this->settlements){
        if(key == county && value.getName() == name){
            return value;
        }
    }
}

Settlement SettlementStatisticsImpl::maxPopulation() const {
    string target = "";
    long max = 0;
    for(auto &[key, value] : this->settlements) {
        if(max < value.getPopulation()){
            target = key;
            max = value.getPopulation();
        }

    }
    return this->settlements.find(target)->second;
}

Settlement SettlementStatisticsImpl::minPopulation() const {
    string target = "";
    long min = settlements.begin()->second.getPopulation();
    for(auto &[key, value] : this->settlements) {
        if(min >= value.getPopulation()){
            target = key;
            min = value.getPopulation();
        }

    }
    return this->settlements.find(target)->second;

}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> result;
    for(auto &[key, value] : this->settlements){
        if(value.getName() == name){
            result.push_back(value);
        }
    }
    return result;
}

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &filename) {
        ifstream f(filename);
        if(!f){
            throw runtime_error("Cannot open file");

        }
        string line;
        getline(f,line);
        while(getline(f, line)) {
            stringstream ss(line);
            string name, code, population;
            getline(ss,name,',');
            getline(ss,code,',');
            getline(ss,population);
            if(population == ""){
                population = "0";
            }
            long long pop = stoll(population);
            Settlement s(name, code, pop);
            this->settlements.insert(make_pair(code, s));

        }

}

