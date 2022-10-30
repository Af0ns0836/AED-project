#ifndef AED_PROJECT_FUNCTIONS_H
#define AED_PROJECT_FUNCTIONS_H

#include "UC.h"
#include "BST.h"
#include "Class.h"
#include "Schedule.h"
#include "Student.h"
#include <set>
#include <utility>
using namespace std;

extern UC ALGA, AM1, FP, FSC, MD, AED, BD, F2, SO, LDTS, FSI, IPC, LBAW, PFL, RC;

extern vector<Class*> turmas_leic;

extern vector<Schedule*> horarios_leic;

extern set<pair<int, string>> student_pairs;

extern BST b, *root;

extern void setUCs();

extern void createClasses();

extern void getClassLectures();

extern void getStudents();

extern void sortClassSchedules();

extern void createStudentBST();

extern void printStudentBST();

#endif
