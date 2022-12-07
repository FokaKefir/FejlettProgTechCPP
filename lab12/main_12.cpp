#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "GraduationDao.h"
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"
#include "SettlementStatisticsImpl.h"


string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

void task1() {
    // ADMIN
    GraduationDao *dao = new GraduationDaoImpl();
    dao->enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao->numEnrolled() << endl;

    for (int i = 0; i < numSubjects; ++i) {
        dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }
    dao->computeAverage();

    GraduationService *service = new GraduationServiceImpl(dao);
    int id = 2406;
    Student student = service->findById(id);
    cout << student << endl;

    for (int i = 0; i < numSubjects; ++i) {
        cout << subjects[i] << ": " << service->getResultByIdAndSubject(id, subjects[i]) << "\n";
    }

    delete service;
    delete dao;
}

void task2() {
    ifstream fin("telepulesek.csv");
    if (!fin) {
        cout << "File error" << endl;
        exit(1);
    }

    multimap<string, Settlement> settlements;
    string line;
    getline(fin, line);
    while (getline(fin, line)) {
        stringstream ss(line);
        string name;
        string county;
        string strPopulation;

        getline(ss, name, ',');
        getline(ss, county, ',');
        getline(ss, strPopulation, ',');
        int population;
        if (!strPopulation.empty())
            population = stoi(strPopulation);
        else
            population = 0;

        Settlement s(name, county, population);
        settlements.insert({county, s});
    }

    SettlementStatisticsImpl *statistics = new SettlementStatisticsImpl(settlements);

    cout << "Number of settlements: " << statistics->numSettlements() << endl;
    cout << "Number of counties: " << statistics->numCounties() << endl;
    string county = "AB";
    cout << "Number of settlements in " << county << ": " << statistics->numSettlementsByCounty(county) << endl;

    vector<Settlement> settlementsByCounty = statistics->findSettlementsByCounty(county);
    cout << "Settlements in " << county << ":\n";
    for_each(settlementsByCounty.begin(), settlementsByCounty.end(), [](const Settlement &s){
        cout << "\t" << s << "\n";
    });
    cout << endl;

    cout << "Find settlement by name and county: " << statistics->findSettlementsByNameAndCounty("Sebes", county) << endl;
    cout << "Settlement with max population: " << statistics->maxPopulationDensity() << endl;
    cout << "Settlement with min population: " << statistics->minPopulationDensity() << endl;

    string subName = "Valea";
    vector<Settlement> settlementsByName = statistics->findSettlementsByName(subName);
    cout << "Settlements which contains " << subName << ":\n";
    for_each(settlementsByName.begin(), settlementsByName.end(), [](const Settlement &s){
        cout << "\t" << s << "\n";
    });
    cout << endl;

    delete statistics;

}

int main() {
    //task1();
    task2();
    return 0;
}
