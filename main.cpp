#include <iostream>
#include <string>
#include "data_structs&functions.h"

using namespace std;

int main() {
    char userchoice;
    bool done = false;
    setUCs();
    createClasses();
    for (auto c : turmas_leic) {
        getClassLectures(c);
    }


   /* cout << "Turmas-Referencia:" << "\n\n";
    for (const Class* c : turmas_leic) {cout << "(" << c->getClassCode() << "/" << c << ") ";}
    cout << "\n\n";

    cout << "Horarios-Referencia:" << "\n\n";
    for (const Schedule* s : horarios_leic) {cout << "n_aulas=" << s->getLectures().size() << " / " << s << ") \n";}
    cout << "\n\n";

    for (Class* c : turmas_leic) {
        cout << "A turma " << c->getClassCode() << " tem " << c->getSchedule()->getLectures().size() << " aulas por semana:" << '\n';
        for (Lecture l : c->getSchedule()->getLectures()) {
            cout << c->getClassCode() << ' ' << l.getUcCode() << ' ' << l.getWeekDay() << ' ' << l.getStartTime() << ' ' << l.getDuration() << ' ' << l.getType() << '\n';
        }
        cout << '\n';
    }

    turmas_leic[46]->getSchedule()->addLecture(Lecture("bruh", "bruh", 0, 0, "bruh"));
    cout << "\t\t|\n";
    cout << "\t\t| adding a lecture\n";
    cout << "\t\t|\n";
    cout << "\t\tV\n";
    cout << '\n';

    cout << "A turma " << turmas_leic[46]->getClassCode() << " tem " << turmas_leic[46]->getSchedule()->getLectures().size() << " aulas por semana:" << '\n';
    for (Lecture l : turmas_leic[46]->getSchedule()->getLectures()) {
        cout << turmas_leic[46]->getClassCode() << ' ' << l.getUcCode() << ' ' << l.getWeekDay() << ' ' << l.getStartTime() << ' ' << l.getDuration() << ' ' << l.getType() << '\n';
    }*/
    while(!done){
    cout << '\n';
    cout << "==================================== \n";
    cout << "\t\tMENU \t \n";
    cout << "==================================== \n";
    cout << "1.Ocupacao de turmas/ano/UC\n";
    cout << "2.Horario de determinado estudante\n";
    cout << "3.Estudantes em determinada turma/UC/ano\n";
    cout << "4.Estudantes com mais de n UCs\n"; // implica uso de BST(Binary Search Trees)
    cout << "5.Alteracao de horarios \n";
    cout << "Introduza o respetivo numero ou pressione 'q' para terminar: ";
    cin >> userchoice;

    switch (userchoice) {
        case 'q': done = true;
                break;
        case '1': for (Class* c : turmas_leic) {
            cout << "A turma " << c->getClassCode() << " tem " << c->getSchedule()->getLectures().size() << " aulas por semana:" << '\n';
            for (Lecture l : c->getSchedule()->getLectures()) {
                cout << c->getClassCode() << ' ' << l.getUcCode() << ' ' << l.getWeekDay() << ' ' << l.getStartTime() << ' ' << l.getDuration() << ' ' << l.getType() << '\n';
            }
            cout << '\n';
        }
        break;
        /*case'2': ;
        case'3': ;
        case'4': ;
        case'5': ;*/
        }


    }
    return 0;
}