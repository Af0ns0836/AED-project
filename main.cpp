#include <iostream>
#include <string>
#include "data_structs&functions.h"

using namespace std;

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