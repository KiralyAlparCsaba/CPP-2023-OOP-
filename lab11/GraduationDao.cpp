//
// Created by Alpar on 2023. 12. 06..
//

#include <vector>
#include <fstream>
#include <sstream>
#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream f(filename);
    if (!f){
        throw runtime_error("File not found");
    }
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        int id;
        string firstName;
        string lastName;
        ss >> id >> firstName >> lastName;
        students.insert(make_pair(id, Student(id, firstName, lastName)) );
    }

}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream f(filename);
    if (!f){
        throw runtime_error("File not found");
    }
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        int id;
        double grade;
        ss >> id >> grade;
        students.at(id).addGrade(subject, grade);
    }
}

void GraduationDao::computeAverage() {
    for(auto &[id, student] : students){
        student.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int passed = numEnrolled();
    for(auto[id, student] : students){
        if(student.getAverage() < 6){
            passed--;
        }
    }
    return passed;
}

Student GraduationDao::findById(int id) const {
    if(students.find(id) == students.end()){
        throw out_of_range("Nonexistent id");
    }
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0.0;
    for(auto student : students){
        sum += student.second.getGrade(subject);
    }
    return sum / this->students.size();
}

