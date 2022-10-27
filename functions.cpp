#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "functions.h"

using namespace std;

UC ALGA, AM1, FP, FSC, MD, AED, BD, F2, SO, LDTS, FSI, IPC, LBAW, PFL, RC;

vector<Class*> turmas_leic = {};

vector<Schedule*> horarios_leic = {};

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
    RC.setCode("L.EIC025"); RC.setCredits(6);
}

int getClassIndex(const string& s) { //linear search O(n)
    for (int i = 0; i < turmas_leic.size(); i++) {
        if (turmas_leic[i]->getClassCode() == s) {return i;}
    }
    return -1;
}

void createClasses() {
    string class_code;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 16; j++) {
            horarios_leic.emplace_back(new Schedule());
        }
    }
    horarios_leic.pop_back();

    int n = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 16; j++) {
            if (j < 10) {
                class_code = to_string(i)+"LEIC0"+to_string(j);
                turmas_leic.emplace_back(new Class(class_code, horarios_leic[n]));
            } else {
                class_code = to_string(i)+"LEIC"+to_string(j);
                turmas_leic.emplace_back(new Class(class_code, horarios_leic[n]));
            }
            n++;
        }
    }
    turmas_leic.pop_back();
}

void getClassLectures() {
    string class_code;
    ifstream file("../data-given/classes.csv");
    file.ignore(100, '\n');
    vector<string> row;
    string line, word;
    while (file.peek() != EOF) {
        row.clear();
        class_code.clear();
        getline(file, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
                row.push_back(word);
                class_code = row[0];
            }
            turmas_leic[getClassIndex(class_code)]->getSchedule()->addLecture(Lecture(row[1], row[2], stof(row[3]), stof(row[4]), row[5]));
        }
}

void sortClassSchedules() {
    for (auto c : turmas_leic) {
        c->getSchedule()->sortSchedule();
    }
}
