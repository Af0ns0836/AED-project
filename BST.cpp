#include "Student.h"
#include "BST.h"
#include <iostream>
using namespace std;

// Default Constructor definition.
BST ::BST() = default;

// Parameterized Constructor definition.
BST ::BST(Student* student): student_(student), left_(nullptr), right_(nullptr) {}

// Insert function definition.
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

// Inorder traversal function.
// This gives data in sorted order.
void BST::print(BST* root) {
    if (!root) {return;}
    print(root->left_);
    cout << '(' << root->student_->getStudentCode() << " / " << root->student_->getStudentName() << ')' << endl;
    print(root->right_);
}
