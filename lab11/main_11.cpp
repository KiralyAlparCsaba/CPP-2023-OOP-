#include <iostream>
#include <vector>
#include "Student.h"
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImpl.h"

int main() {

Student s1(1, "John", "Doe");
s1.addGrade("Math",8);
s1.addGrade("Physics",9);
s1.addGrade("Romanian",7);
s1.addGrade("Hungarian",9.45);
s1.computeAverage();
cout << s1;


GraduationDao dao(2023);
dao.enrollStudents("C:\\Users\\Alpar\\Documents\\GitHub\\Cpp2023\\lab11\\names.txt");
cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
dao.saveGradesForSubject("Math", "C:\\Users\\Alpar\\Documents\\GitHub\\Cpp2023\\lab11\\math.txt");
dao.saveGradesForSubject("Hungarian", "C:\\Users\\Alpar\\Documents\\GitHub\\Cpp2023\\lab11\\hungarian.txt");
dao.saveGradesForSubject("Romanian", "C:\\Users\\Alpar\\Documents\\GitHub\\Cpp2023\\lab11\\romanian.txt");
dao.computeAverage();

cout <<"Number of passed students: " << dao.numPassed() << endl;


StudentService* service = new StudentServiceImpl(&dao);
cout << "Individual results: " << endl;
int id = 0;
while (id != -1) {
    cout << "Enter ID (-1 for EXIT): ";
    cin >> id;
    if (id == -1) {
        break;
    }
    if (!service->isEnrolled(id)) {
        cout << "Student id=" << id << " not found" << endl;
        continue;
    }
    cout << "Student id=" << id << " results: " << endl;
    bool passed = service->isPassed(id);
    cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
    if (!passed) {
        continue;
    }
    vector<string> subjects = service->getSubjects(id);
    for (int i = 0; i < subjects.size(); ++i) {
        cout << "\t" << subjects[i] << ": " <<
        service->getResultBySubject(id, subjects[i]) << endl;
    }
    cout << "\taverage: " << service->getAverage(id) << endl;
}
delete service;








}