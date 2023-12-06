//
// Created by Alpar on 2023. 12. 06..
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) : id(id), firstName(firstName), lastName(lastName) {

}

int Student::getId() const {
    return this->id;
}

void Student::setId(int id) {
    this->id = id;

}

const string &Student::getFirstName() const {
    return this->firstName;
}

const string &Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {
    this->grades[subject] = grade;


}

double Student::getGrade(const string &subject) {
    if(this->grades.find(subject) == this->grades.end()){
        throw out_of_range("Nonexistent subject");
    }
    return this->grades[subject];
}

const map<string, double> &Student::getGrades() const {
    return this->grades;
}

void Student::computeAverage() {
    this->average = 0.0;
    double average = 0;
    for (auto[key, value] : grades) {
        if(value < 5){
            return;
        }
        average += value;
    }
    this->average = average/grades.size();
}


double Student::getAverage() const {
    return this->average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "ID:" <<  student.id << " First Name:" << student.firstName << " Last Name:" << student.lastName << " Average:" << student.average << "\n";
    for(auto grade : student.grades){
        os << grade.first << " " << grade.second << "\n";
    }
    return os;

}
