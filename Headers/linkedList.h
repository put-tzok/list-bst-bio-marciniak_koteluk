#pragma once 

#include <iostream>

class Node {
    int key;
    Node* next;
    
    public:
        Node* getNextNode();
        Node* setNextNode(Node* node);

        int getValue();
        int setValue(int val);

    Node();
    Node(int value, Node* node);
    ~Node();
};

class LinkedList {
    unsigned int size;
    Node* head;

    public:
        int getSize();
        int setSize(int val);

        Node* getHead();
        Node* setHead(Node* node);

        Node* insertElement(int value);
        Node* searchElementWithValue(int value);
        void deleteElementWithValue(int value);
    
    LinkedList();
    ~LinkedList();
};
