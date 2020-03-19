#pragma once

#include <iostream>

class Node {
    int key;
    Node* left;
    Node* right;

    public:
        Node* getLeftNode();
        Node* getRightNode();

        int getValue();
        int setValue(int val);
    
    Node();
    Node(int value);
    ~Node();
};

class BinarySearchTree {
    unsigned int size;
    Node* root;

    public:
        int getSize();
        int setSize(int val);

        Node* getRoot();
        Node* setRoot(Node* node);
        
        Node* insertElement(int value);
        Node** searchElementWithValue(int value);
        Node* deleteElementWithValue(int value);
        Node** getMaximum(Node*);
    
    BinarySearchTree();
    ~BinarySearchTree();
};