#ifndef AED_PROJECT_DATA_STRUCTS_FUNCTIONS_H
#define AED_PROJECT_DATA_STRUCTS_FUNCTIONS_H

#include "UC.h"
#include "Class.h"
#include "Schedule.h"

extern UC ALGA, AM1, FP, FSC, MD, AED, BD, F2, SO, LDTS, FSI, IPC, LBAW, PFL, RC;

extern Class _1LEIC01, _1LEIC02, _1LEIC03, _1LEIC04, _1LEIC05, _1LEIC06, _1LEIC07, _1LEIC08, _1LEIC09, _1LEIC10,
        _1LEIC11, _1LEIC12, _1LEIC13, _1LEIC14, _1LEIC15, _2LEIC01, _2LEIC02, _2LEIC03, _2LEIC04, _2LEIC05, _2LEIC06,
        _2LEIC07, _2LEIC08, _2LEIC09, _2LEIC10, _2LEIC11, _2LEIC12, _2LEIC13, _2LEIC14, _2LEIC15, _3LEIC01, _3LEIC02,
        _3LEIC03, _3LEIC04, _3LEIC05, _3LEIC06, _3LEIC07, _3LEIC08, _3LEIC09, _3LEIC10, _3LEIC11, _3LEIC12, _3LEIC13,
        _3LEIC14, _3LEIC15;

extern Schedule h1LEIC01, h1LEIC02, h1LEIC03, h1LEIC04, h1LEIC05, h1LEIC06, h1LEIC07, h1LEIC08, h1LEIC09, h1LEIC10,
        h1LEIC11, h1LEIC12, h1LEIC13, h1LEIC14, h1LEIC15, h2LEIC01, h2LEIC02, h2LEIC03, h2LEIC04, h2LEIC05, h2LEIC06,
        h2LEIC07, h2LEIC08, h2LEIC09, h2LEIC10, h2LEIC11, h2LEIC12, h2LEIC13, h2LEIC14, h2LEIC15, h3LEIC01, h3LEIC02,
        h3LEIC03, h3LEIC04, h3LEIC05, h3LEIC06, h3LEIC07, h3LEIC08, h3LEIC09, h3LEIC10, h3LEIC11, h3LEIC12, h3LEIC13,
        h3LEIC14, h3LEIC15;


extern vector<Class> turmas_leic;

extern vector<Schedule> horarios_turmas;

extern void setUCs();

extern void setClassCodes();

extern void getClassLectures(Class turma);

extern void setClassSchedules();

#endif
