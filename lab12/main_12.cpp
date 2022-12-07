#include <iostream>
#include <algorithm>
#include "GraduationDao.h"
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"


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

}

int main() {
    task2();
    return 0;
}
