#include "GraduationServiceImpl.h"


GraduationServiceImpl::GraduationServiceImpl(GraduationDao *dao) {
    this->dao = dao;
}


Student GraduationServiceImpl::findById(int id) const {
    auto results = dao->findById(id);
    return results;
}

double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const {
    auto results = dao->findById(id);
    return results.getGrade(subject);
}
