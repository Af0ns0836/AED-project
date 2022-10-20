#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "data_structs&functions.h"

using namespace std;

UC ALGA, AM1, FP, FSC, MD, AED, BD, F2, SO, LDTS, FSI, IPC, LBAW, PFL, RC;

Class _1LEIC01 = Class("1LEIC01"), _1LEIC02 = Class("1LEIC02"), _1LEIC03 = Class("1LEIC03"),
        _1LEIC04 = Class("1LEIC04"), _1LEIC05 = Class("1LEIC05"), _1LEIC06 = Class("1LEIC06"),
        _1LEIC07 = Class("1LEIC07"), _1LEIC08 = Class("1LEIC08"), _1LEIC09 = Class("1LEIC09"),
        _1LEIC10 = Class("1LEIC10"), _1LEIC11 = Class("1LEIC11"), _1LEIC12 = Class("1LEIC12"),
        _1LEIC13 = Class("1LEIC13"), _1LEIC14 = Class("1LEIC14"), _1LEIC15 = Class("1LEIC15"),
        _2LEIC01 = Class("2LEIC01"), _2LEIC02 = Class("2LEIC02"), _2LEIC03 = Class("2LEIC03"),
        _2LEIC04 = Class("2LEIC04"), _2LEIC05 = Class("2LEIC05"), _2LEIC06 = Class("2LEIC06"),
        _2LEIC07 = Class("2LEIC07"), _2LEIC08 = Class("2LEIC08"), _2LEIC09 = Class("2LEIC09"),
        _2LEIC10 = Class("2LEIC10"), _2LEIC11 = Class("2LEIC11"), _2LEIC12 = Class("2LEIC12"),
        _2LEIC13 = Class("2LEIC13"), _2LEIC14 = Class("2LEIC14"), _2LEIC15 = Class("2LEIC15"),
        _3LEIC01 = Class("3LEIC01"), _3LEIC02 = Class("3LEIC02"), _3LEIC03 = Class("3LEIC03"),
        _3LEIC04 = Class("3LEIC04"), _3LEIC05 = Class("3LEIC05"), _3LEIC06 = Class("3LEIC06"),
        _3LEIC07 = Class("3LEIC07"), _3LEIC08 = Class("3LEIC08"), _3LEIC09 = Class("3LEIC09"),
        _3LEIC10 = Class("3LEIC10" ), _3LEIC11 = Class("3LEIC11"), _3LEIC12 = Class("3LEIC12"),
        _3LEIC13 = Class("3LEIC13" ),  _3LEIC14 = Class("3LEIC14"), _3LEIC15 = Class("3LEIC15");

vector<Class> turmas_leic = {_1LEIC01, _1LEIC02, _1LEIC03, _1LEIC04, _1LEIC05, _1LEIC06, _1LEIC07, _1LEIC08,_1LEIC09,
                             _1LEIC10, _1LEIC11, _1LEIC12, _1LEIC13, _1LEIC14, _1LEIC15, _2LEIC01, _2LEIC02, _2LEIC03,
                             _2LEIC04, _2LEIC05, _2LEIC06, _2LEIC07, _2LEIC08, _2LEIC09, _2LEIC10, _2LEIC11, _2LEIC12,
                             _2LEIC13, _2LEIC14, _2LEIC15, _3LEIC01, _3LEIC02, _3LEIC03, _3LEIC04, _3LEIC05, _3LEIC06,
                             _3LEIC07, _3LEIC08, _3LEIC09, _3LEIC10, _3LEIC11, _3LEIC12, _3LEIC13, _3LEIC14, _3LEIC15};

Schedule h1LEIC01, h1LEIC02, h1LEIC03, h1LEIC04, h1LEIC05, h1LEIC06, h1LEIC07, h1LEIC08, h1LEIC09, h1LEIC10,
        h1LEIC11, h1LEIC12, h1LEIC13, h1LEIC14, h1LEIC15, h2LEIC01, h2LEIC02, h2LEIC03, h2LEIC04, h2LEIC05, h2LEIC06,
        h2LEIC07, h2LEIC08, h2LEIC09, h2LEIC10, h2LEIC11, h2LEIC12, h2LEIC13, h2LEIC14, h2LEIC15, h3LEIC01, h3LEIC02,
        h3LEIC03, h3LEIC04, h3LEIC05, h3LEIC06, h3LEIC07, h3LEIC08, h3LEIC09, h3LEIC10, h3LEIC11, h3LEIC12, h3LEIC13,
        h3LEIC14, h3LEIC15

vector<Schedule> horarios_turmas = {h1LEIC01, h1LEIC02, h1LEIC03, h1LEIC04, h1LEIC05, h1LEIC06, h1LEIC07, h1LEIC08, h1LEIC09,
                                    h1LEIC10, h1LEIC11, h1LEIC12, h1LEIC13, h1LEIC14, h1LEIC15, h2LEIC01, h2LEIC02, h2LEIC03,
                                    h2LEIC04, h2LEIC05, h2LEIC06, h2LEIC07, h2LEIC08, h2LEIC09, h2LEIC10, h2LEIC11, h2LEIC12,
                                    h2LEIC13, h2LEIC14, h2LEIC15, h3LEIC01, h3LEIC02, h3LEIC03, h3LEIC04, h3LEIC05, h3LEIC06,
                                    h3LEIC07, h3LEIC08, h3LEIC09, h3LEIC10, h3LEIC11, h3LEIC12, h3LEIC13, h3LEIC14, h3LEIC15};


void setUCs() { //first semester UC's only
    ALGA.setCode("L.EIC001"); ALGA.setCredits(4.5);
    AM1.setCode("L.EIC002"); AM1.setCredits(6);
    FP.setCode("L.EIC003"); FP.setCredits(6);
    FSC.setCode("L.EIC004"); FP.setCredits(6);
    MD.setCode("L.EIC005"); MD.setCredits(6);
    AED.setCode("L.EIC011"); AED.setCredits(6);
    BD.setCode("L.EIC012"); BD.setCredits(6);
    F2.setCode("L.EIC013"); F2.setCredits(4.5);
    SO.setCode("L.EIC014"); SO.setCredits(6);
    LDTS.setCode("L.EIC015"); LDTS.setCredits(6);
    FSI.setCode("L.EIC021"); FSI.setCredits(6);
    IPC.setCode("L.EIC022"); IPC.setCredits(4.5);
    LBAW.setCode("L.EIC023"); LBAW.setCredits(6);
    PFL.setCode("L.EIC024"); PFL.setCredits(6);
    RC.setCode("L.EIC0025"); RC.setCredits(6);
}

Schedule getClassLectures(const Class& turma, Schedule schedule) {
    string class_code = turma.getClassCode();
    ifstream file("../data-given/classes.csv");
    vector<string> row;
    string line, word;
    while (file.peek() != EOF) {
        row.clear();
        getline(file, line);
        stringstream s(line);
        if (line.rfind(class_code, 0) == 0) {
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
            Lecture l = Lecture(row[1], row[2], stof(row[3]), stof(row[4]), row[5]);
            schedule.addLecture(l);
        }
    }
    schedule.sortSchedule();
    return schedule;
}

void setClassSchedules() {
    int i = 0;
    for (Class& c : turmas_leic) {
        c.updateSchedule(getClassLectures(c, horarios_turmas[i]));
        i++;
    }
}
