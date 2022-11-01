#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

#include "Schedule.h"
#include "Student.h"
#include <list>
#include <string>
using namespace std;

class Class {
    public:
        Class();
        explicit Class(string class_code);
        explicit Class(string class_code, Schedule* horario);
        explicit Class(string class_code, Schedule* horario, list<Student*> alunos);
        string getClassCode() const;
        Schedule* getSchedule();
        list<Student*> getStudentList();
        void addStudent(Student* s);

    private:
        string class_code_;
        Schedule* horario_;
        list<Student*> alunos_;
};

#endif
