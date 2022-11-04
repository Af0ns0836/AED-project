#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

#include "Schedule.h"
#include <string>
using namespace std;

class Student {
    public:
        Student();
        explicit Student(int upCode, string name);
        explicit Student(int upCode, string name, Schedule* horario);
        int getStudentCode() const;
        string getStudentName() const;
        Schedule* getStudentSchedule();
        bool operator == (const Student& s) const {return upCode_ == s.upCode_;}
        bool operator != (const Student& s) const {return !operator==(s);}

    private:
        int upCode_;
        string name_;
        Schedule* horarioEstudante_;
};

#endif
