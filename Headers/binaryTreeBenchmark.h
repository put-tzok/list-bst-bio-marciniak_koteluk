#pragma once

#include <assert.h>
#include <signal.h>
#include <time.h>
#include "binaryTree.h"

void fillIncreasing(int *arr, unsigned int size);
void shuffle(int *arr, unsigned int size);
bool isBST(Node *element);
void insertIncreasing(int *arr, unsigned int size, BinarySearchTree* bst);
void insertRandom(int *arr, unsigned int size, BinarySearchTree* bst);
void searchTree(BinarySearchTree* bst, int* values, unsigned int size);
void deleteElementsFromTree(BinarySearchTree* bst, int* values, unsigned int size);
