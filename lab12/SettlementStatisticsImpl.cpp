#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const multimap<string, Settlement> &settlements) : settlements(settlements) {}

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    int s = 0;
    for(auto it = settlements.begin(), end = settlements.end(); it != end; it = settlements.upper_bound(it->first)){
        s++;
    }
    return s;
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return settlements.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> settlementsVec;
    auto settlementsByCounty = settlements.equal_range(county);
    for (auto it = settlementsByCounty.first; it != settlementsByCounty.second; it++) {
        settlementsVec.push_back((*it).second);
    }
    return settlementsVec;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    auto settlementsByCounty = settlements.equal_range(county);
    auto it = find_if(settlementsByCounty.first, settlementsByCounty.second, [&](const pair<string, Settlement> &s){
        return (name == s.second.getName());
    });
    return it->second;
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    auto it = max_element(settlements.begin(), settlements.end(), [](const pair<string, Settlement> &s1, const pair<string, Settlement> &s2){
        return s1.second.getPopulation() < s2.second.getPopulation();
    });
    return (*it).second;
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    auto it = min_element(settlements.begin(), settlements.end(), [](const pair<string, Settlement> &s1, const pair<string, Settlement> &s2){
        return s1.second.getPopulation() < s2.second.getPopulation();
    });
    return (*it).second;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> settlementsByName;
    for (auto it = settlements.begin(); it != settlements.end(); it++) {
        const Settlement &s = (*it).second;
        if (s.getName().find(name) != string::npos) {
            settlementsByName.push_back(s);
        }
    }
    return settlementsByName;
}

