#include <iostream>
#include <string>
#include "functions.h"
#include "BST.h"

using namespace std;

int main() {
    char userchoice;
    bool done = false;

    setUCs();
    getUCEmptyRosters();
    createClasses();
    getClassLectures();
    sortClassSchedules();
    getStudents();
    createEmptyStudentSchedules();
    createStudentBST();
    getAllStudentLectures(root);
    fillUCRosters();
    fillUCSchedules();


   /* cout << '\n';
    cout << "=======================================================" << "\n\n";
    for (auto uc : UCs) { //estudantes das turmas de todas as cadeiras
        cout << "CADEIRA: " << uc->getCode() << "\n\n";
        for (auto c : uc->getUCClasses()) {
            cout << c->getClassCode() << " tem " << c->getStudentList().size() << " estudantes:" << '\n';
            for (auto s : c->getStudentList()) {
                cout << s->getStudentCode() << ' ' << s->getStudentName() << '\n';
            }
            cout << '\n';
        }
        cout << '\n';
    }*/


    cout << '\n';
    cout << "=======================================================" << "\n\n";
    for (auto uc : UCs) { //horarios das turmas de todas as cadeiras
        cout << "CADEIRA: " << uc->getCode() << ' ' << uc->getName() << "\n\n";
        for (auto c : uc->getUCClasses()) {
            cout << c->getClassCode() << '\n';
            for (auto s : c->getSchedule()->getLectures()) {
                cout << s.getUcCode() << ' ' << s.getWeekDay() << ' ' << s.getStartTime() << ' ' << s.getDuration() << ' ' << s.getType() << '\n';

            }
            cout << '\n';
        }
        cout << '\n';
    }

    /*for (Class* c : turmas_leic) {
        cout << "A turma " << c->getClassCode() << " tem " << c->getSchedule()->getLectures().size() << " aulas por semana:" << '\n';
        for (Lecture l : c->getSchedule()->getLectures()) {
            cout << c->getClassCode() << ' ' << l.getUcCode() << ' ' << l.getWeekDay() << ' ' << l.getStartTime() << ' ' << l.getDuration() << ' ' << l.getType() << '\n';
        }
        cout << '\n';
    }*/


    cout <<'\n';
    while(!done){
        cout << "==================================== \n";
        cout << "\t\tMENU \t \n";
        cout << "==================================== \n";
        cout << "1.Ocupacao de turmas/ano/UC\n";
        cout << "2.Horario de determinado estudante\n";
        cout << "3.Estudantes em determinada turma/UC/ano\n";
        cout << "4.Estudantes com mais n de UCs\n"; // implica uso de BST(Binary Search Trees)
        cout << "5.Alteracao de horarios \n";
        cout << "Introduza o respetivo numero ou 'q' para terminar: ";
        cin >> userchoice;
        switch (userchoice) {
            case 'q': done = true;
                    break;
            case 'Q': done = true;
                break;

            case '1':{
                string tua;
                string tua2;
                cout << '\n' << "Introduza onde deseja saber o numero de estudantes(turma/UC/ano):  ";
                unsigned long n = 0;
                cin >> tua;
                if (tua == "turma"){
                    cout << "Digite a turma:  ";
                    cin >> tua2;
                    // nome_turma = 1LEIC01;

                    cout << "Existem " << n << " estudantes na " << tua2;
                }
                else if (tua == "UC"){
                    cout << "Digite a sigla da UC:  ";
                    cin >> tua2;
                   for(auto uc : UCs) {//cadeira L.EIC001 tem 31 estudantes
                       string nome_uc = uc->getName();
                       if(nome_uc == tua2) {
                           for (auto c: uc->getUCClasses()) {
                               n += c->getStudentList().size();
                           }
                       }
                   }
                    cout << "Existem " << n << " estudantes em " << tua2;
                    cout << "\n";
                }
                else{
                    cout << "Digite o ano:  ";

                    cout << "Existem " << n << " estudantes no " << tua2;
                }
            }
            break;

            case'2': {
                cout << '\n' << "Introduza o codigo do aluno: ";
                int student_code;
                cin >> student_code;
                Student *temp = getStudentLocation(student_code)->getStudent();
                cout << '\n' << "Horario do aluno (" << temp->getStudentCode() << " / " << temp->getStudentName() << "):\n";
                for (auto l: temp->getStudentSchedule()->getLectures()) {
                    cout << l.getUcCode() << ' ' << l.getWeekDay() << ' ' << l.getStartTime() << ' ' << l.getDuration()
                         << ' ' << l.getType() << '\n';
                }
                cout << "\n";
                break;
            }

            case'3': {
                cout << '\n' << "Introduza onde deseja saber os estudantes(turma/UC/ano):  ";
                int n;
                string choice;
                string choice2;
                cin >> choice;
                if (choice == "turma"){
                    cout << "Digite a turma:  ";
                    cin >> choice2;
                    BST::treeTraversal(root,choice2);
                    cout << "Existem " << n << " estudantes na " << choice;}
                else if (choice == "UC"){
                    cout << "Digite a UC:  ";
                    BST::treeTraversal(root,choice2);
                    cout << "Existem " << n << " estudantes em " << choice;}
                else{
                    cout << "Digite o ano:  ";
                    BST::treeTraversal(root,choice2);
                    cout << "Existem " << n << " estudantes no " << choice;}
                cout << "\n";
                break;
            }
            /*case'4': ;
            case'5': ;*/
        }
    }

    return 0;
}
