//
// Created by Alpar on 2023. 12. 06..
//

#ifndef CPP_2022_GRADUATIONDAO_H
#define CPP_2022_GRADUATIONDAO_H

#include <string>
#include <map>
#include <iostream>
#include "Student.h"

class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void saveGradesForSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
    double getAverageBySubject(const string &subject) const;
// throws out_of_range exception for nonexistent id
    Student findById(int id) const;
};


#endif //CPP_2022_GRADUATIONDAO_H
