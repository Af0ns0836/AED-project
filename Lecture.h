#ifndef AED_PROJECT_LECTURE_H
#define AED_PROJECT_LECTURE_H

#include <string>
using namespace std;

class Lecture {
    public:
        Lecture();
        Lecture(string uc_code, string  week_day, float start_time, float duration, string type);
        Lecture(Lecture const &l); //copy
        string getUcCode();
        void setUcCode(string uc_code);
        string getWeekDay();
        void setWeekDay(string week_day);
        float getStartTime() const;
        void setStartTime(float start_time);
        float getDuration() const;
        void setDuration(float duration);
        string getType();
        void setType(string type);

    private:
        string uc_code_;
        string week_day_;
        float start_time_;
        float duration_;
        string type_;
};

#endif
