#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    Node(string i, Node* l, Node* r) {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void insert(string element) {
    Node* newNode = new Node(element, NULL, NULL);

    newNode->info = element;
    newNode->leftchild = NULL;
    newNode->rightchild = NULL;

    Node* parent = NULL;
    Node* current = root;

    search(element, parent, current);

    if(parent == NULL) {
        root = newNode;
        return;
    }

    if(element < parent->info) {
        parent->leftchild = newNode;
    } else {
        parent->rightchild = newNode;
    }
    }
    void search(string element, Node*& parent, Node*& currentNode) {
        currentNode = root;
        parent = NULL;

        while((currentNode != NULL) && (currentNode->info != element)) {
            parent = currentNode;

            if(element < currentNode->info) {
                currentNode = currentNode->leftchild;
            } else {
                currentNode = currentNode->rightchild;
            }
        }
    }

    void inorder(Node* ptr) {
        if(root == NULL) {
            cout << "Tree is empty" << endl;
            return;
        }
        if(ptr != NULL) {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(Node* ptr) {
        if(root == NULL) {
            cout << "Tree is empty" << endl;
            return;
        }
        if(ptr != NULL) {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }

    void postorder(Node* ptr) {
        if(root == NULL) {
            cout << "Tree is empty" << endl;
            return;
        }
        if(ptr != NULL) {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " ";
        }
    }
};