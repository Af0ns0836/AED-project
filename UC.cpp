#include "UC.h"
#include <utility>

UC::UC() = default;

UC::UC(string uc_code, string name, float ects): uc_code_(std::move(uc_code)), name_(std::move(name)), ects_(ects) {}

UC::UC(string uc_code, string name, float ects, vector<Class*> turmas_da_uc): uc_code_(std::move(uc_code)), name_(std::move(name)), ects_(ects), turmas_da_uc_(std::move(turmas_da_uc)) {}

string UC::getCode() {return uc_code_;}

vector<Class*> UC::getUCClasses() {
    return turmas_da_uc_;
}

//! Adiciona aulas da UC ao vetor de turmas.
void UC::addUCClass(Class* c) {
    turmas_da_uc_.push_back(c);
}

string UC::getName() {return name_;}
