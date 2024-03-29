#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <set>
#include "functions.h"

using namespace std;

vector<UC*> UCs = {};

vector<Class*> turmas_leic = {};

vector<Schedule*> horarios_leic = {};

set<pair<int, string>> student_pairs = {};

vector<Schedule*> student_schedules = {};

BST b, *root = nullptr;

//! string para letra minuscula
string lower(string s) {
    for (char& c : s) {
        c = tolower(c);
    }
    return s;
}

//! String para letra maiuscula
string upper(string s) {
    for (char& c : s) {
        c = toupper(c);
    }
    return s;
}
//! Cria o vetor de UCs
void setUCs() { //first semester UC's only
    UCs.emplace_back(new UC("L.EIC001", "ALGA", 4.5));
    UCs.emplace_back(new UC("L.EIC002", "AM1", 6));
    UCs.emplace_back(new UC("L.EIC003", "FP", 6));
    UCs.emplace_back(new UC("L.EIC004", "FSC", 6));
    UCs.emplace_back(new UC("L.EIC005", "MD", 6));
    UCs.emplace_back(new UC("L.EIC011", "AED", 6));
    UCs.emplace_back(new UC("L.EIC012", "BD", 6));
    UCs.emplace_back(new UC("L.EIC013", "F2", 4.5));
    UCs.emplace_back(new UC("L.EIC014", "SO", 6));
    UCs.emplace_back(new UC("L.EIC015", "LDTS", 6));
    UCs.emplace_back(new UC("L.EIC021", "FSI", 6));
    UCs.emplace_back(new UC("L.EIC022", "IPC", 4.5));
    UCs.emplace_back(new UC("L.EIC023", "LBAW", 6));
    UCs.emplace_back(new UC("L.EIC024", "PFL", 6));
    UCs.emplace_back(new UC("L.EIC025", "RC", 6));
}

//!  Vai buscar as UCs da respetiva turma
void getUCEmptyRosters() {
    ifstream file("../data-given/classes_per_uc.csv");
    if(!file) {
        cout << "Error opening file. " << endl;
    }
    file.ignore(100, '\n');
    vector<string> row;
    string line, word;
    while (file.peek() != EOF) {
        row.clear();
        getline(file, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        for (auto uc : UCs) {
            if (row[0] == uc->getCode()) {
                uc->addUCClass(new Class(row[1], new Schedule(), {}));
            }
        }

    }
    file.close();
}

//! vai buscar o indice da aula dentro do vetor
int getClassIndex(const string& s) { //linear search O(n) because it's <50 classes
    for (int i = 0; i < turmas_leic.size(); i++) {
        if (turmas_leic[i]->getClassCode() == s) {return i;}
    }
    return -1;
}
//! Cria as aulas
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

//! Vai buscar todas as aulas de todas as turmas ao ficheiro
void getClassLectures() {
    string class_code;
    ifstream file("../data-given/classes.csv");
    if(!file) {
        cout<<" Error opening file. " << endl;
    }
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
    file.close();
}
//! Vai buscar os estudantes ao ficheiro
void getStudents() {
    ifstream file("../data-given/students_classes.csv");
    if(!file) {
        cout << "Error opening file. " << endl;
    }
    file.ignore(100, '\n');
    pair<int, string> p;
    vector<string> row;
    string line, word;
    while (file.peek() != EOF) {
        row.clear();
        getline(file, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        p.first = stoi(row[0]);
        p.second = row[1];
        student_pairs.insert(p);
    }
    file.close();
}
//! Sort aos horarios de todas as turmas
void sortClassSchedules() {
    for (auto c : turmas_leic) {
        c->getSchedule()->sortSchedule();
    }
}
//! Adiciona os estudantes da respetiva UC
void fillUCRosters() {
    ifstream file("../data-given/students_classes.csv");
    if(!file) {cout << "Error opening file. " << endl;}
    file.ignore(100, '\n');
    vector<string> row;
    string line, word;
    while (file.peek() != EOF) {
        row.clear();
        getline(file, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        for (auto uc : UCs) {
            if (row[2] == uc->getCode()) {
                for (auto c : uc->getUCClasses()) {
                    if (row[3] == c->getClassCode()) {
                        c->addStudent(new Student(stoi(row[0]), row[1]));
                        }
                    }
                }
            }
        }
    file.close();
}

//! Preenche o vetor de UCs
void fillUCSchedules() {
    ifstream file("../data-given/classes.csv");
    if(!file) {cout << "Error opening file. " << endl;}
    file.ignore(100, '\n');
    vector<string> row;
    string line, word;
    while (file.peek() != EOF) {
        row.clear();
        getline(file, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        for (auto uc : UCs) {
            if (row[1] == uc->getCode()) {
                for (auto c : uc->getUCClasses()) {
                    if (row[0] == c->getClassCode()) {
                        c->getSchedule()->addLecture(Lecture(row[1], row[2], stof(row[3]),
                                                             stof(row[4]), row[5]));
                    }
                }
            }
        }
    }
    file.close();
}

//! cria a StudentBST
void createStudentBST() {
    root = b.insert(root, new Student());
    int i = 0;
    for (const auto& p : student_pairs) {
        b.insert(root, new Student(p.first, p.second, student_schedules[i]));
        i++;
    }
}

//! devolve a localizacao do estudante, procura pelo seu codigo up dentro da arvore
BST* getStudentLocation(int upCode) {
    BST* found = b.search(root, upCode);
    return found;
}

//! cria um vetor vazio para os horarios de cada estudante
void createEmptyStudentSchedules() {
    for (auto p : student_pairs) {
        student_schedules.emplace_back(new Schedule());
    }
}

//! Le o ficheiro students_classes e preenche a arvore
void getStudentLectures(BST* node) {
    ifstream file("../data-given/students_classes.csv");
    if(!file) {cout << "Error opening file. " << endl;}
    file.ignore(100, '\n');
    vector<string> row;
    string line, word;
    while (file.peek() != EOF) {
        row.clear();
        getline(file, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (row[0] == to_string(node->getStudent()->getStudentCode())) {
            for (auto c : turmas_leic) {
                if (row[3] == c->getClassCode()) {
                    for (auto l : c->getSchedule()->getLectures()) {
                        if (row[2] == l.getUcCode()) {
                            node->getStudent()->getStudentSchedule()->addLecture(l);
                        }
                    }
                }
            }
        }
    }
    node->getStudent()->getStudentSchedule()->sortSchedule();
    file.close();
}

//! Busca todas as aulas dos estudantes
void getAllStudentLectures(BST* root) {
    if (!root) {return;}
    getAllStudentLectures(root->getLeftBranch());
    getStudentLectures(root);
    getAllStudentLectures(root->getRightBranch());
}

//! Devolve os Estudantes com mais de n UCs
void task4(BST* root, unsigned char n=0) {
    if (!root) {return;}
    set<string> s;
    task4(root->getLeftBranch(), n);
    for (auto l : root->getStudent()->getStudentSchedule()->getLectures()) {
        s.insert(l.getUcCode());
    }
    task4(root->getRightBranch(), n);
    if (s.size() >= n) {cout << root->getStudent()->getStudentCode() << ' ' << root->getStudent()->getStudentName() << '\n';}
    s.clear();
}
