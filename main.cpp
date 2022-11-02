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
                string tua3;
                cout << '\n' << "Introduza onde deseja saber o numero de estudantes(turma/UC/ano): ";
                cin >> tua;
                cout << '\n';
                if (lower(tua) == "turma"){
                    unsigned n;
                    cout << "Digite a UC a qual a turma pertence: ";
                    cin >> tua2;
                    cout << '\n';
                    // nome_turma = 1LEIC01;
                    cout << "Digite o codigo da turma: ";
                    cin >> tua3;
                    cout << '\n';
                    for(auto uc : UCs) {
                        string nome_uc = uc->getName();
                        if(nome_uc == tua2) {
                            for (auto c: uc->getUCClasses()) {
                                n = c->getStudentList().size();
                            }
                        }
                    }
                    cout << "Estão inscritos " << n << " estudantes na turma " << tua3 << '\n';
                }
                else if (lower(tua) == "uc") {
                    cout << "Digite a sigla da UC:  ";
                    cin >> tua2;
                    unsigned n = 0;
                   for(auto uc : UCs) {//cadeira L.EIC001 tem 31 estudantes
                       string nome_uc = uc->getName();
                       if(nome_uc == upper(tua2)) {
                           for (auto c: uc->getUCClasses()) {
                               n += c->getStudentList().size();
                           }
                       }
                   }
                    cout << '\n';
                    cout << "Estão inscritos " << n << " estudantes na UC: " << tua2;
                    cout << "\n";
                }
                else if (lower(tua) == "ano"){
                    unsigned n = 0;
                    cout << "Digite o ano: ";
                    cin >> tua2;
                    if (tua2 == "1") {
                        vector<string> v = {"ALGA", "AM1", "FP", "FSC", "MD"};
                        for (auto uc : UCs) {
                            if (uc->getName() == v[0] || uc->getName() == v[1] || uc->getName() == v[2] || uc->getName() == v[3] || uc->getName() == v[4]) {
                                for (auto c : uc->getUCClasses()) {
                                    n += c->getStudentList().size();
                                }
                            }
                        }
                    }
                    if (tua2 == "2") {
                        vector<string> v = {"AED", "BD", "F2", "SO", "LDTS"};
                        for (auto uc : UCs) {
                            if (uc->getName() == v[0] || uc->getName() == v[1] || uc->getName() == v[2] || uc->getName() == v[3] || uc->getName() == v[4]) {
                                for (auto c : uc->getUCClasses()) {
                                    n += c->getStudentList().size();
                                }
                            }
                        }
                    }
                    if (tua2 == "3") {
                        vector<string> v = {"FSI", "IPC", "LBAW", "PFL", "RC"};
                        for (auto uc : UCs) {
                            if (uc->getName() == v[0] || uc->getName() == v[1] || uc->getName() == v[2] || uc->getName() == v[3] || uc->getName() == v[4]) {
                                for (auto c : uc->getUCClasses()) {
                                    n += c->getStudentList().size();
                                }
                            }
                        }
                    }
                    cout << '\n' << "Estão inscritos " << n << " estudantes no " << tua2 << " ano."<< '\n';
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
                cout << '\n' << "Introduza onde deseja saber os estudantes(turma/UC/ano): ";
                string choice;
                string choice2;
                string choice3;
                cin >> choice;
                cout << '\n';
                if (lower(choice) == "turma") {
                    cout << "Digite a UC a qual a turma pertence: ";
                    cin >> choice2;
                    cout << '\n';
                    // nome_turma = 1LEIC01;
                    cout << "Digite o codigo da turma: ";
                    cin >> choice3;
                    cout << '\n';
                    for (auto uc : UCs) {
                        string nome_uc = uc->getName();
                        if (nome_uc == choice2) {
                            cout << "Alunos inscritos na turma " << choice3 << " de " << nome_uc << ":\n";
                            for (auto c: uc->getUCClasses()) {
                                if (c->getClassCode() == upper(choice3)) {
                                for(auto s : c->getStudentList()) {
                                    cout << s->getStudentCode() << ' ' << s->getStudentName() << '\n';
                                    }
                                }
                            }
                        }
                    }
                cout << '\n';
                } else if (lower(choice) == "uc") {
                    cout << "Digite a UC:  ";
                    cin >> choice2;
                    for (auto uc : UCs) {
                        string nome_uc = uc->getName();
                        if (nome_uc == choice2) {
                            cout << "Alunos inscritos na turma " << choice2 << " da UC (" << nome_uc << "):\n";
                            for (auto c: uc->getUCClasses()) {
                                for(auto s : c->getStudentList()) {
                                    cout << s->getStudentCode() << ' ' << s->getStudentName() << '\n';
                                }
                            }
                        }
                    }
                } else if (lower(choice) == "ano") {
                    cout << "Digite o ano: ";
                    cin >> choice2;
                    cout << '\n';
                    if (choice2 == "1") {
                        vector<string> v = {"ALGA", "AM1", "FP", "FSC", "MD"};
                        cout << "Alunos inscritos no ano " << choice2 << " da LEIC: \n";
                        for (auto uc : UCs) {
                            if (uc->getName() == v[0] || uc->getName() == v[1] || uc->getName() == v[2] || uc->getName() == v[3] || uc->getName() == v[4]) {
                                for (auto c : uc->getUCClasses()) {
                                    for (auto s : c->getStudentList()) {
                                        cout << s->getStudentCode() << ' ' << s->getStudentName() << '\n';
                                    }
                                }
                            }
                        }
                    }
                    if (choice2 == "2") {
                        vector<string> v = {"AED", "BD", "F2", "SO", "LDTS"};
                        cout << "Alunos inscritos no ano " << choice2 << " da LEIC: \n";
                        for (auto uc : UCs) {
                            if (uc->getName() == v[0] || uc->getName() == v[1] || uc->getName() == v[2] || uc->getName() == v[3] || uc->getName() == v[4]) {
                                for (auto c : uc->getUCClasses()) {
                                    for (auto s : c->getStudentList()) {
                                        cout << s->getStudentCode() << ' ' << s->getStudentName() << '\n';
                                    }
                                }
                            }
                        }
                    }
                    if (choice2 == "3") {
                        vector<string> v = {"FSI", "IPC", "LBAW", "PFL", "RC"};
                        cout << "Alunos inscritos no ano " << choice2 << " da LEIC: \n";
                        for (auto uc : UCs) {
                            if (uc->getName() == v[0] || uc->getName() == v[1] || uc->getName() == v[2] || uc->getName() == v[3] || uc->getName() == v[4]) {
                                for (auto c : uc->getUCClasses()) {
                                    for (auto s : c->getStudentList()) {
                                        cout << s->getStudentCode() << ' ' << s->getStudentName() << '\n';
                                    }
                                }
                            }
                        }
                    }
                    cout << "\n";
                }
                break;
            }
            /*case'4': ;
            case'5': ;*/
        }
    }
    return 0;
}
