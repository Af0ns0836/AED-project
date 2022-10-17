#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

#include "Schedule.h"
#include <string>
using namespace std;

class Class {
    public:
        Class();
        explicit Class(string class_code);
        explicit Class(string class_code, Schedule horario);
        Class(Class const &c1);
        string getClassCode() const;
        Schedule getSchedule();
        void setSchedule(const Schedule& horario);

    private:
        string class_code_;
        Schedule horario_;
};


#endif
