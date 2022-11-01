#include "Class.h"

#include <utility>

Class::Class() = default;

Class::Class(string class_code): class_code_(std::move(class_code)) {}

Class::Class(string class_code, Schedule* horario): class_code_(std::move(class_code)), horario_(horario) {}

Class::Class(string class_code, Schedule* horario, list<Student*> alunos): class_code_(std::move(class_code)), horario_(horario), alunos_(std::move(alunos)) {}

string Class::getClassCode() const {return class_code_;}

Schedule* Class::getSchedule() {return horario_;}

list<Student*> Class::getStudentList() {return alunos_;}

void Class::addStudent(Student *s) {
    alunos_.push_back(s);
}
