#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Class.h"
#include "UC.h"
#include "Schedule.h"
using namespace std;

UC ALGA, AM1, FP, FSC, MD, AED, BD, F2, SO, LDTS, FSI, IPC, LBAW, PFL, RC, UP;

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

vector<Class> turmas_leic = {_1LEIC01, _1LEIC02, _1LEIC03, _1LEIC04, _1LEIC05, _1LEIC06, _1LEIC07, _1LEIC08,_1LEIC09, _1LEIC10, _1LEIC11,
                             _1LEIC12, _1LEIC13, _1LEIC14, _1LEIC15, _2LEIC01, _2LEIC02, _2LEIC03, _2LEIC04, _2LEIC05, _2LEIC06, _2LEIC07, _2LEIC08,
                             _2LEIC09, _2LEIC10, _2LEIC11, _2LEIC12, _2LEIC13, _2LEIC14, _2LEIC15, _3LEIC01, _3LEIC02, _3LEIC03, _3LEIC04, _3LEIC05,
                             _3LEIC06, _3LEIC07, _3LEIC08, _3LEIC09, _3LEIC10, _3LEIC11, _3LEIC12, _3LEIC13, _3LEIC14, _3LEIC15};

void setUCs() {         //first semester UC's only
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
    UP.setCode("UP001"); UP.setCredits(1.5);
}

Class getClassLectures(Class turma) {
    vector<Lecture> v;
    string class_code = turma.getClassCode();
    ifstream file;
    file.open(R"(C:\Users\diogo\Desktop\AED-project\data-given\classes.csv)", ios::in); //o path pra mim so funciona se eu colocar assim, vejam se nos vossos pc's funciona se puserem data-given/classes.csv
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
            v.push_back(l);
        }
    }
    Schedule s = Schedule(v);
    s.sortSchedule();
    turma.setSchedule(s);
    return turma;
}

void setClassSchedules() {
    for (Class& c : turmas_leic) {
        c = getClassLectures(c);
    }
}

int main() {
    int userchoice;
    setUCs();
    setClassSchedules();

    //lista dos horarios de cada turma só pra checkar se ficou a funcionar
    for (Class c : turmas_leic) {
        cout << "A turma " << c.getClassCode() << " tem " << c.getSchedule().getLectures().size() << " aulas por semana:" << '\n';
        for (Lecture l : c.getSchedule().getLectures()) {
            cout << c.getClassCode() << ' ' << l.getUcCode() << ' ' << l.getWeekDay() << ' ' << l.getStartTime() << ' ' << l.getDuration() << ' ' << l.getType() << '\n';
        }
        cout << '\n';
    }

    cout << "==================================== \n";
    cout << "\t\tMENU \t \n";
    cout << "==================================== \n";
    cout << "1.Ocupacao de turmas/ano/UC\n";
    cout << "2.Horario de determinado estudante\n";
    cout << "3.Estudantes em determinada turma/UC/ano\n";
    cout << "4.Estudantes com mais de n UCs\n"; // implica uso de BST(Binary Search Trees)
    cout << "5.Alteracao de horarios \n";
    cout << "Introduza o respetivo numero: ";
    cin >> userchoice;

    //switch (condition) {

    //}

    return 0;
}
