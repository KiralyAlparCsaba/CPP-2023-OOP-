#include <iostream>
#include "Student.h"
#include "GraduationDao.h"

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








}