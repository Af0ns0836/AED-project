#include "UC.h"
#include <utility>

UC::UC() = default;

UC::UC(string uc_code, string name, float ects): uc_code_(std::move(uc_code)), name_(std::move(name)), ects_(ects) {}

UC::UC(string uc_code, string name, float ects, vector<Class*> turmas_da_uc): uc_code_(std::move(uc_code)), name_(std::move(name)), ects_(ects), turmas_da_uc_(std::move(turmas_da_uc)) {}

string UC::getCode() {return uc_code_;}

void UC::setCode(std::string uc_code) {this->uc_code_ = std::move(uc_code);}

float UC::getCredits() const {return ects_;}

void UC::setCredits(float ects) {
    this->ects_ = ects;
}

vector<Class*> UC::getUCClasses() {
    return turmas_da_uc_;
}

void UC::setUCClasses(vector<Class*> v) {
    this->turmas_da_uc_ = std::move(v);
}

void UC::addUCClass(Class* c) {
    turmas_da_uc_.push_back(c);
}

string UC::getName() {return name_;}
