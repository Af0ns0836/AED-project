#include "ScheduleManager.h"
#include <iostream>
#include <string>
#include <queue>
#include "functions.h"
#include "BST.h"

ScheduleManager::ScheduleManager() = default;

//! Menu do programa
void ScheduleManager::menu() {
    char userchoice;
    bool done = false;
    cout <<'\n';
    while(!done){
        cout << "==================================== \n";
        cout << "\t\tMENU \t \n";
        cout << "==================================== \n";
        cout << "1.Ocupacao de turmas/ano/UC\n";
        cout << "2.Horario de determinado estudante\n";
        cout << "3.Estudantes em determinada turma/UC/ano\n";
        cout << "4.Estudantes com mais de n UCs\n"; // implica uso de BST(Binary Search Trees)
        cout << "5.Alteracao de horarios \n";
        cout << "6.Processar a fila de pedidos \n";
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
                    cout << "Digite o codigo da turma: ";
                    cin >> tua3;
                    cout << '\n';
                    for(auto uc : UCs) {
                        string nome_uc = uc->getName();
                        if(nome_uc == upper(tua2)) {
                            for (auto c: uc->getUCClasses()) {
                                if (c->getClassCode() == upper(tua3)) {
                                    n = c->getStudentList().size();
                                }
                            }
                        }
                    }
                    cout << "Estao inscritos " << n << " estudantes na turma " << upper(tua3) << '\n';
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
                    cout << "Estao inscritos " << n << " estudantes na UC: " << upper(tua2);
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
                    cout << '\n' << "Estao inscritos " << n << " estudantes no " << tua2 << " ano."<< '\n';
                }
            }
                break;

            case'2': {
                cout << '\n' << "Introduza o codigo do aluno: ";
                int student_code;
                cin >> student_code;
                cout << '\n';
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
                    cout << "Digite o codigo da turma: ";
                    cin >> choice3;
                    cout << '\n';
                    for (auto uc : UCs) {
                        string nome_uc = uc->getName();
                        if (nome_uc == upper(choice2)) {
                            cout << "Alunos inscritos na turma " << upper(choice3) << " de " << nome_uc << ":\n";
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
                        if (nome_uc == upper(choice2)) {
                            cout << "Alunos inscritos em" << upper(nome_uc) << "\n";
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
            case'4': {
                cout << '\n' << "Introduza o numero minimo de UCs: ";
                int n;
                cin >> n;
                cout << '\n';
                cout << "Os seguintes alunos estao inscritos em mais de " << n << " UCs:" << '\n';
                task4(root, n);
                cout << '\n';
                break;
            }
            case'5': {
                cout << '\n' << "Introduza o codigo do aluno: ";
                string student_code;
                cin >> student_code;
                cout << '\n' << "Pretende adicionar ou remover o aluno de uma turma? (a/r) ";
                string choice;
                cin >> choice;
                if (lower(choice) == "a") {
                    cout << '\n' << "A turma pratica pertence a que UC? ";
                    string choice2;
                    cin >> choice2;
                    cout << '\n' << "Introduza o codigo da turma: ";
                    string choice3;
                    cin >> choice3;
                    vector<string> v = {student_code, choice2, choice3, choice};
                    createRequest(v);
                    cout << '\n' << "Queue size=" << q_.size() << '\n';
                }
                if (lower(choice) == "r") {
                    cout << '\n' << "A turma pratica pertence a que UC? ";
                    string choice2;
                    cin >> choice2;
                    cout << '\n' << "Introduza o codigo da turma: ";
                    string choice3;
                    cin >> choice3;
                    vector<string> v = {student_code, choice2, choice3, choice};
                    createRequest(v);
                    cout << '\n' << "Queue size=" << q_.size() << '\n';
                }
                break;
            }
            case'6': {
                cout << '\n' << "The queue will be processed." << '\n';
                analyseRequests();
                break;
            }
        }
    }
}

//! Le os ficheiros e preenche e inicializa as estruturas de dados
void ScheduleManager::readFiles() {
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
}

//! Adiciona os pedidos a queue
void ScheduleManager::createRequest(const vector<string>& request) {
    q_.push(request);
}

//! Verifica se o pedido e valido
bool ScheduleManager::checkValidRequest(vector<string> request) {
    int upcode = stoi(request[0]);
    string uc_name = request[1];
    string class_code = request[2];
    string option = request[3];
    if (option == "a") {
        for (auto uc : UCs) {
            if (uc->getName() == uc_name) {
                for (auto c : uc->getUCClasses()) {
                    if (class_code == c->getClassCode()) {
                        for (auto s : c->getStudentList()) {
                            if (s->getStudentCode() == upcode) {
                                cout << "Nao foi possivel adicionar o estudante a esta turma." << '\n';
                                return false;
                            }
                        }
                    }
                }
            }
        }
    } else if (option == "r") {
        Student* s = getStudentLocation(stoi(q_.front()[0]))->getStudent();
        for (auto uc : UCs) {
            if (uc->getName() == uc_name) {
                for (auto c : uc->getUCClasses()) {
                    if (class_code == c->getClassCode()) {
                        for (auto s1 : c->getStudentList()) {
                            if (s1 == s) {
                                return true;
                            } else {};
                        }
                        return false;
                    }
                }
            }
        }
    }
    unsigned char min = 250;
        for (auto uc : UCs) {
            if (uc->getName() == uc_name) {
                for (auto c : uc->getUCClasses()) {
                    if (c->getStudentList().size() < min) {min = c->getStudentList().size();}
                }
            }
        }
    if (option == "a") {
        for (auto uc : UCs) {
            if (uc->getName() == uc_name) {
                for (auto c : uc->getUCClasses()) {
                    if (class_code == c->getClassCode()) {
                        return min <= c->getStudentList().size()+1 <= min+3;
                    }
                }
            }
        }
    } else if (option == "r") {
        for (auto uc : UCs) {
            if (uc->getName() == uc_name) {
                for (auto c : uc->getUCClasses()) {
                    if (class_code == c->getClassCode()) {
                        return min <= c->getStudentList().size()-1 <= min+3;
                    }
                }
            }
        }
    }
    return false;
}

//! Trata do pedido
void ScheduleManager::analyseRequests() {
    while (!q_.empty()) {
        if (checkValidRequest(q_.front())) {
            for (auto uc : UCs) {
                if (uc->getName() == q_.front()[1]) {
                    for (auto c : uc->getUCClasses()) {
                        if (c->getClassCode() == q_.front()[2]) {
                            if (q_.front()[3] == "a") {
                                Student* s = getStudentLocation(stoi(q_.front()[0]))->getStudent();
                                c->addStudent(s);
                                cout << "Student " << s->getStudentCode() << ' ' << s->getStudentName() << " has been added to " << c->getClassCode() << '\n';
                            } else if (q_.front()[3] == "r") {
                                Student* s = getStudentLocation(stoi(q_.front()[0]))->getStudent();
                                for (auto &s1 : c->getStudentList()) {
                                    if (s1 == s) {
                                        delete s1;
                                    }
                                }
                                cout << "Student " << s->getStudentCode() << ' ' << s->getStudentName() << " has been removed from " << c->getClassCode() << '\n';
                            }
                        }
                    }
                }
            }
        }
        q_.pop();
    }
}
