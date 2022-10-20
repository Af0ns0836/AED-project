#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

#include "Lecture.h"
#include <vector>

class Schedule {
    public:
        Schedule();
        explicit Schedule(vector<Lecture> aulas);
        void updateLectures(vector<Lecture> aulas);
        vector<Lecture> getLectures();
        void sortSchedule();
        void addLecture(const Lecture& aula);

    private:
        vector<Lecture> aulas_;
};

#endif
