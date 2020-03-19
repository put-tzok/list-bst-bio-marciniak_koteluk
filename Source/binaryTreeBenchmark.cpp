#include "../Headers/binaryTreeBenchmark.h"

void fillIncreasing(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void shuffle(int *arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % i;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

bool isBST(Node *element) {
    if (element == NULL) {
        return true;
    }
    if (element->getLeftNode() == NULL && element->getRightNode() == NULL) {
        return true;
    }
    if (element->getLeftNode() == NULL && element->getRightNode() != NULL) {
        return (element->getValue() < element->getRightNode()->getValue()) && isBST(element->getRightNode());
    }
    if (element->getLeftNode() != NULL && element->getRightNode() == NULL) {
        return (element->getValue() > element->getLeftNode()->getValue()) && isBST(element->getLeftNode());
    }

    return (element->getValue() > element->getLeftNode()->getValue())
        && (element->getValue() < element->getRightNode()->getValue())
        && isBST(element->getLeftNode())
        && isBST(element->getRightNode());
}

void insertIncreasing(int *arr, int size, BinarySearchTree* bst) {
    for (int i = 0; i < size; i++) {
        bst->insertElement(arr[i]);
    }
}

void insertRandom(int *arr, int size, BinarySearchTree* bst) {
    shuffle(arr, size);
    for (int i = 0; i < size; i++) {
        bst->insertElement(arr[i]);
    }
}

void searchTree(BinarySearchTree* bst, int* values, int size) {
    for (unsigned int k = 0; k < size; k++) {
        Node** foundNode = bst->searchElementWithValue(values[k]);
        Node* currentNode = *foundNode;
        assert(currentNode != NULL);
        assert(currentNode->getValue() == values[k]);
    }
}

void deleteElementsFromTree(BinarySearchTree* bst, int* values, int size) {
    for (unsigned int l = 0, m = size; l < size; l++, m--) {
        assert(bst->getSize() == m);
        bst->deleteElementWithValue(values[l]);
        assert(isBST(bst->getRoot()));
    }
}