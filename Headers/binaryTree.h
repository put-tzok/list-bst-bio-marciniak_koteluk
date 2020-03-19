#pragma once

#include <iostream>

class Node {
    public:
        int key;
        Node* left;
        Node* right;

    Node();
    Node(int value);
    ~Node();
};

class BinarySearchTree {
    public:
        unsigned int size;
        Node* root;
        
        Node* insertElement(int value);
        Node** searchElementWithValue(int value);
        Node* deleteElementWithValue(int value);
        Node** getMaximum(Node*);
    
    BinarySearchTree();
    ~BinarySearchTree();
};