#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

unsigned int ns[] = { 10, /* TODO: fill values which will be used as lists' sizes */ };

class Node {
    int key;
    Node* next;

    public:
        Node* getNextNode(Node* root) { return root->next; }
        int getValue() { return this->key; }
        int setValue(int val) { 
            this->key = val; 
            return this->key;
        }
    
    Node()
        : key(NULL), next(nullptr) {
            std::cout << "Node successfully created" << std::endl;
        }
    
    Node(int value)
        : key(value), next(nullptr) {
            std::cout << "Node with value: " << value << " successfully created" << std::endl;
        }
    
    ~Node() {
        std::cout << "Node successfully deleted" << std::endl;
    }
};

class LinkedList {
    unsigned int size;
    Node* head;

    public:
        int getSize() { return this->size; }
        int setSize() { return ++this->size; }
        Node* getHead() { return this->head; }
        Node* setHead(Node* node) {
            this->head = node;
            return this->head;
        }
        Node* insertElement(int value) { return NULL; }
        Node* searchElementWithValue(int value) { return NULL; }
        Node* deleteElementWithValue(int value) { return NULL; }
    
    LinkedList()
        : size(0), head(nullptr) {
            std::cout << "Linked list successfully initialized" << std::endl;
        }
    
    ~LinkedList() {
        std::cout << "Linked list successfully deleted" << std::endl;
    }
};

void fill_increasing(int *t, int n) {
    for (int i = 0; i < n; i++) {
        t[i] = i;
    }
}

void shuffle(int *t, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % i;
        int temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }
}

int main() {
    bool shuffleArrayInCurrentIteration[] = { false, true };
    LinkedList* list = new LinkedList();

   for (unsigned int i = 0; i < sizeof(shuffleArrayInCurrentIteration) / sizeof(*shuffleArrayInCurrentIteration); i++) {
        bool checkShuffle = shuffleArrayInCurrentIteration[i];

        for (unsigned int j = 0; j < sizeof(ns) / sizeof(*ns); j++) {
            unsigned int n = ns[j];

            int *t = new int[n];
            fill_increasing(t, n);

            if (checkShuffle) {
                shuffle(t, n);
            }

            clock_t insertion_time = clock();
            for (unsigned int k = 0; k < n; k++) {
                Node* insertedNode = list->insertElement(t[k]);
                assert(insertedNode != NULL);
                assert(insertedNode->getValue() == t[k]);
            }
            insertion_time = clock() - insertion_time;

            shuffle(t, n);

            clock_t search_time = clock();
            for (unsigned int k = 0; k < n; k++) {
                Node* insertedNode = list->searchElementWithValue(t[k]);
                assert(insertedNode != NULL);
                assert(insertedNode->getValue() == t[k]);
            }
            search_time = clock() - search_time;

            shuffle(t, n);

            for (unsigned int k = 0, l = n; k < n; k++, l--) {
                assert(list->getSize() == l);
                list->deleteElementWithValue(t[k]);
            }
            assert(list->getSize() == 0);
            assert(list->getHead() == NULL);

            free(t);

            printf("%d\t%s\t%f\t%f\n", n, checkShuffle ? "true" : "false",
                    (double)insertion_time / CLOCKS_PER_SEC,
                    (double)search_time / CLOCKS_PER_SEC);
        }
    }
    return 0;
}
