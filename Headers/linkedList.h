#pragma once 

#include <iostream>

class Node {
    public:
        int key;
        Node* next;
    
    Node();
    Node(Node* node);
    Node(int value, Node* node);
    ~Node();
};

class LinkedList {
    public:
        unsigned int size;
        Node* head;

        Node* setHead(Node* node);
        Node* insertElement(int value);
        Node* searchElementWithValue(int value);
        void deleteElementWithValue(int value);
    
    LinkedList();
    ~LinkedList();
};
