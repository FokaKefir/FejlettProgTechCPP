#ifndef CPP_2022_GRADUATIONSERVICEIMPL_H
#define CPP_2022_GRADUATIONSERVICEIMPL_H

#include "GraduationService.h"
#include "GraduationDaoImpl.h"

class GraduationServiceImpl : public GraduationService{
private:
    GraduationDao *dao;
public:
    GraduationServiceImpl(GraduationDao *dao);
    Student findById(int id) const override;
    double getResultByIdAndSubject(int id, const string &subject) const override;

};


#endif //CPP_2022_GRADUATIONSERVICEIMPL_H
