#include "Class.h"

#include <utility>

Class::Class() = default;

Class::Class(string class_code): class_code_(std::move(class_code)) {}

Class::Class(const Class &c1) { //copy constructor
    this->class_code_ = c1.class_code_;
    this->horario_ = c1.horario_;
}

string Class::getClassCode() const {return class_code_;}

void Class::setClassCode(const string &class_code) {this->class_code_ = class_code;}

Schedule Class::getSchedule() {return horario_;}

void Class::setSchedule(const Schedule& horario) {this->horario_ = horario;}






