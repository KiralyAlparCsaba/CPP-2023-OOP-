//
// Created by Alpar on 2023. 12. 06..
//

#include "StudentServiceImpl.h"

#include <stdexcept>

bool StudentServiceImpl::isEnrolled(int id) const {
    try {
        dao->findById(id);
        return true;
    } catch (const out_of_range &e) {
        return false;
    }
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    try {
        vector<string> subjects;
        Student student = dao->findById(id);
        for (const auto &grade : student.getGrades()) {
            subjects.push_back(grade.first);
        }
        return subjects;
    } catch (const out_of_range &e) {
        throw runtime_error("Invalid ID");
    }
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    try {
        return dao->findById(id).getGrade(subject);
    } catch (const out_of_range &e) {
        throw runtime_error("Invalid ID");
    }
}

double StudentServiceImpl::getAverage(int id) const {
    try {
         return dao->findById(id).getAverage();
    } catch (const out_of_range &e) {
        throw runtime_error("Invalid ID");
    }
}

bool StudentServiceImpl::isPassed(int id) const {
    try {
        if (dao->findById(id).getAverage() >= 6) {
            return true;
        } else {
            return false;
        }
    } catch (const out_of_range &e) {
        throw runtime_error("Invalid ID");
    }
}

