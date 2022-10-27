#include "Class.h"

#include <utility>

Class::Class() = default;

Class::Class(string class_code): class_code_(std::move(class_code)) {}

Class::Class(string class_code, Schedule* horario): class_code_(std::move(class_code)), horario_(horario) {}

string Class::getClassCode() const {return class_code_;}

Schedule* Class::getSchedule() {return horario_;}
