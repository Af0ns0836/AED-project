#include "Lecture.h"
#include <utility>

Lecture::Lecture() = default;

Lecture::Lecture(string  uc_code, string  week_day, float start_time, float duration, string  type):
uc_code_(std::move(uc_code)), week_day_(std::move(week_day)), start_time_(start_time),
duration_(duration), type_(std::move(type)) {}

Lecture::Lecture(const Lecture &l): uc_code_(l.uc_code_), week_day_(l.week_day_), start_time_(l.start_time_), duration_(l.duration_), type_(l.type_) {}

string Lecture::getUcCode() {return uc_code_;}

string Lecture::getWeekDay() {return week_day_;}

float Lecture::getStartTime() const {return start_time_;}

float Lecture::getDuration() const {return duration_;}

string Lecture::getType() {return type_;}


