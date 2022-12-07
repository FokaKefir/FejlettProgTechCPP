#ifndef CPP_2022_GRADUATIONSERVICE_H
#define CPP_2022_GRADUATIONSERVICE_H

#include "Student.h"

class GraduationService {
public:
    virtual Student findById(int id) const = 0;
    virtual double getResultByIdAndSubject(int id, const string& subject) const = 0;
};


#endif //CPP_2022_GRADUATIONSERVICE_H
