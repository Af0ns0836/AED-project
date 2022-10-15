#include "UC.h"
#include <utility>

UC::UC() = default;

UC::UC(string uc_code, float ects): uc_code_(std::move(uc_code)), ects_(ects) {}

string UC::getCode() {return uc_code_;}

void UC::setCode(std::string uc_code) {this->uc_code_ = std::move(uc_code);}

float UC::getCredits() const {return ects_;}

void UC::setCredits(float ects) {this->ects_ = ects;}
