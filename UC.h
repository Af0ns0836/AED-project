#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include <string>
#include <list>
#include "Class.h"

using namespace std;

class UC {
    public:
        UC();
        UC(string uc_code, string name, float ects);
        UC(string uc_code, string name, float ects, vector<Class*> turmas_da_uc);
        string getCode();
        void setCode(string uc_code);
        string getName();
        float getCredits() const;
        void setCredits(float ects);
        vector<Class*> getUCClasses();
        void setUCClasses(vector<Class*> v);
        void addUCClass(Class* c);

    private:
        string uc_code_;
        string name_;
        float ects_;
        vector<Class*> turmas_da_uc_;
};

#endif
