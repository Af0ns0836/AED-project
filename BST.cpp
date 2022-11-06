#include "Student.h"
#include "BST.h"
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

//! Default Constructor definition.
BST ::BST() = default;

//! Parameterized Constructor definition.
BST ::BST(Student* student): student_(student), left_(nullptr), right_(nullptr) {}

//! Return ao node student
Student* BST::getStudent() {
    return student_;
}
//! Devolve o branch da direita
BST* BST::getRightBranch() {
    return right_;
}
//! Devolve o branch da esquerda
BST* BST::getLeftBranch() {
    return left_;
}

//! insere os students na arvore
BST* BST ::insert(BST* root, Student *student) {
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(student);
    }

    // Insert data.
    if (student->getStudentCode() > root->student_->getStudentCode()) {
        // Insert right node data, if the student upcode
        // to be inserted is greater than 'root' student's upcode.

        // Process right nodes.
        root->right_ = insert(root->right_, student);
    }
    else if (student->getStudentCode() < root->student_->getStudentCode()){
        // Insert left node data, if the student upcode
        // to be inserted is smaller than 'root' student's upcode.

        // Process left nodes.
        root->left_ = insert(root->left_, student);
    }

    // Return 'root' node, after insertion.
    return root;
}

//! Procura um student na arvore pelo seu codigo up
BST* BST::search(BST* root, int upCode) {
    int depth = 0;
    BST* temp;
    temp = root;
    // Run the loop untill temp points to a NULL pointer.
    while(temp != nullptr) {
        depth++;
        if (temp->getStudent()->getStudentCode() == upCode) {
            return temp;
        }
            // Shift pointer to left child.
        else if(temp->getStudent()->getStudentCode() > upCode)
            temp = temp->getLeftBranch();
            // Shift pointer to right child.
        else
            temp = temp->getRightBranch();
    }
    return nullptr;
}

// Inorder traversal function.
// This gives data in sorted order.
//! Imprime quantas aulas o student tem por semana
void BST::print(BST* root) {
    if (!root) {return;}
    print(root->left_);
    cout << '(' << root->student_->getStudentCode() << " / " << root->student_->getStudentName() << " / " << root->getStudent()->getStudentSchedule()->getLectures().size() << " aulas por semana)" << endl;
    print(root->right_);
}
