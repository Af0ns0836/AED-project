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

extern vector<UC*> UCs;

extern vector<Class*> turmas_leic;

extern vector<Schedule*> horarios_leic;

extern set<pair<int, string>> student_pairs;

extern vector<Schedule*> student_schedules;

extern BST b, *root;

extern string lower(string s);

extern string upper(string s);

extern void setUCs();

extern void getUCEmptyRosters();

extern void createClasses();

extern void getClassLectures();

extern void getStudents();

extern void sortClassSchedules();

extern void fillUCRosters();

extern void fillUCSchedules();

extern void createStudentBST();

extern void printStudentBST();

extern void searchPrintStudentLocation(int upCode);

extern BST* getStudentLocation(int upCode);

extern void createEmptyStudentSchedules();

extern void getStudentLectures(BST* node);

extern void getAllStudentLectures(BST* root);

#endif
