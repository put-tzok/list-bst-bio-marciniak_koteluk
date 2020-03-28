#pragma once

#include <iostream>

class Node {
    int key;
    Node* left;
    Node* right;

    public:
        Node* getLeftNode();
        Node* setLeftNode(Node* node);
        Node* getRightNode();
        Node* setRightNode(Node* node);

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
        unsigned int getSize();
        unsigned int setSize(int val);

        Node* getRoot();
        Node* setRoot(Node* node);
        
        Node* insertElement(int value);
        Node* searchElementWithValue(Node* node, int value);
        Node* deleteElementWithValue(int value);
        Node* getMaximum(Node* node);
    
    BinarySearchTree();
    ~BinarySearchTree();
};