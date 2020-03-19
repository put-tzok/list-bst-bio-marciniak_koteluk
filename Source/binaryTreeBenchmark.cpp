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
    if (element->left == NULL && element->right == NULL) {
        return true;
    }
    if (element->left == NULL && element->right != NULL) {
        return (element->key < element->right->key) && isBST(element->right);
    }
    if (element->left != NULL && element->right == NULL) {
        return (element->key > element->left->key) && isBST(element->left);
    }

    return (element->key > element->left->key)
        && (element->key < element->right->key)
        && isBST(element->left)
        && isBST(element->right);
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
        assert(currentNode->key == values[k]);
    }
}

void deleteElementsFromTree(BinarySearchTree* bst, int* values, int size) {
    for (unsigned int l = 0, m = size; l < size; l++, m--) {
        assert(bst->size == m);
        bst->deleteElementWithValue(values[l]);
        assert(isBST(bst->root));
    }
}