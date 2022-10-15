#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include <string>
using namespace std;

class UC {
    public:
        UC();
        UC(string uc_code, float ects);
        string getCode();
        void setCode(string uc_code);
        float getCredits() const;
        void setCredits(float ects);

    private:
        string uc_code_;
        float ects_{};
};

#endif
