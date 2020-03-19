#pragma once

#include <assert.h>
#include <signal.h>
#include <time.h>
#include "binaryTree.h"

void fill_increasing(int *arr, int size);
void shuffle(int *arr, int size);
bool is_bst(Node *element);
void insertIncreasing(int *arr, int size, BinarySearchTree* bst);
void insertRandom(int *arr, int size, BinarySearchTree* bst);
void searchTree(BinarySearchTree* bst, int* values, int size);
void deleteElementsFromTree(BinarySearchTree* bst, int* values, int size);
