#include "Class.h"

#include <utility>

Class::Class() = default;

Class::Class(string class_code): class_code_(std::move(class_code)) {}

string Class::getClassCode() const {return class_code_;}

Schedule Class::getSchedule() {return horario_;}

void Class::setSchedule(const Schedule& horario) {this->horario_ = horario;}

Class::Class(const Class &c1) {
    this->class_code_ = c1.class_code_;
    this->horario_ = c1.horario_;
}

Class::Class(string class_code, Schedule horario): class_code_(std::move(class_code)), horario_(std::move(horario)) {}
