#include <algorithm>
#include <utility>
#include "Schedule.h"

Schedule::Schedule() = default;

Schedule::Schedule(vector<Lecture> aulas): aulas_(std::move(aulas)) {}

void Schedule::setLectures(vector<Lecture> aulas) {this->aulas_ = std::move(aulas);}

vector<Lecture> Schedule::getLectures() {return aulas_;}

static const string weekday_names[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void Schedule::sortSchedule() {
    std::sort(aulas_.begin(), aulas_.end(), [](Lecture a, Lecture b) {
        int n1 = distance(weekday_names, find(weekday_names, weekday_names+weekday_names->size(), a.getWeekDay()));
        int n2 = distance(weekday_names, find(weekday_names, weekday_names+weekday_names->size(), b.getWeekDay()));
        if (n1 == n2) {return a.getStartTime() < b.getStartTime();}
        return n1 < n2;});
}

void Schedule::addLecture(const Lecture& aula) {aulas_.push_back(aula);}
