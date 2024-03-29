#include "Student.h"

#include <utility>

Student::Student(): upCode_(-1), name_("ROOT_STUDENT"), horarioEstudante_(new Schedule()) {}

Student::Student(int upCode, string name): upCode_(upCode), name_(std::move(name)) {}

Student::Student(int upCode, string name, Schedule *horario): upCode_(upCode), name_(std::move(name)), horarioEstudante_(horario) {}

string Student::getStudentName() const {return name_;}

int Student::getStudentCode() const {return upCode_;}

Schedule *Student::getStudentSchedule() {return horarioEstudante_;}
