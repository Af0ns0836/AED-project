#include "Lecture.h"
#include <utility>

Lecture::Lecture() = default;

Lecture::Lecture(string  uc_code, string  week_day, float start_time, float duration, string  type):
uc_code_(std::move(uc_code)), week_day_(std::move(week_day)), start_time_(start_time),
duration_(duration), type_(std::move(type)) {}

string Lecture::getUcCode() {return uc_code_;}

void Lecture::setUcCode(string uc_code) {this->uc_code_ = std::move(uc_code);}

string Lecture::getWeekDay() {return week_day_;}

void Lecture::setWeekDay(string week_day) {this->week_day_ = std::move(week_day);}

float Lecture::getStartTime() const {return start_time_;}

void Lecture::setStartTime(float start_time) {this->start_time_ = start_time;}

float Lecture::getDuration() const {return duration_;}

void Lecture::setDuration(float duration) {this->duration_ = duration;}

string Lecture::getType() {return type_;}

void Lecture::setType(string type) {this->type_ = std::move(type);}
