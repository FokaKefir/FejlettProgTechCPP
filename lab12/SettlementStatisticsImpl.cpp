#include "SettlementStatisticsImpl.h"

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    for(  multimap<char,int>::iterator it = mymm.begin(), end = mymm.end(); it != end; it = mymm.upper_bound(it->first)){
        cout << it->first << ' ' << it->second << endl;
    }
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return 0;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    return vector<Settlement>();
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    return Settlement(__cxx11::basic_string(), __cxx11::basic_string(), 0);
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    return Settlement(__cxx11::basic_string(), __cxx11::basic_string(), 0);
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    return Settlement(__cxx11::basic_string(), __cxx11::basic_string(), 0);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    return vector<Settlement>();
}

SettlementStatisticsImpl::SettlementStatisticsImpl(const multimap<string, Settlement> &settlements) : settlements(settlements) {}
