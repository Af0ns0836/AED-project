#ifndef AED_PROJECT_BST_H
#define AED_PROJECT_BST_H

#include "Student.h"
#include <iostream>
using namespace std;

class BST {
    public:
        BST();
        explicit BST(Student* student);
        Student* getStudent();
        BST* getRightBranch();
        BST* getLeftBranch();
        BST* insert(BST*, Student* student);
        BST* search(BST*, int upCode);
        void print(BST*);

    private:
        Student* student_;
        BST* left_;
        BST* right_;
};

#endif
