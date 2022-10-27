#ifndef AED_PROJECT_DATA_STRUCTS_FUNCTIONS_H
#define AED_PROJECT_DATA_STRUCTS_FUNCTIONS_H

#include "UC.h"
#include "Class.h"
#include "Schedule.h"

extern UC ALGA, AM1, FP, FSC, MD, AED, BD, F2, SO, LDTS, FSI, IPC, LBAW, PFL, RC;

extern vector<Class*> turmas_leic;

extern vector<Schedule*> horarios_leic;

extern void setUCs();

extern void createClasses();

extern void getClassLectures(Class* c);

#endif
