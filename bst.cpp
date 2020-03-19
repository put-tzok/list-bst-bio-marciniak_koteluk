#include "Headers/binaryTree.h"
#include "Headers/binaryTreeBenchmark.h"

unsigned int ns[] = { 10, /* TODO: fill values which will be used as lists' sizes */ };

void insertBinary(int *arr, int size, BinarySearchTree* bst) {
    // TODO: implement
}

char *insertFunctionsNames[] = { "Increasing", "Random", "Binary" };
void (*insertFunctions[])(int*, int, BinarySearchTree*) = { insertIncreasing, insertRandom, insertBinary };

int main(int argc, char **argv) {
    BinarySearchTree* bst = new BinarySearchTree();
    for (unsigned int i = 0; i < sizeof(insertFunctions) / sizeof(*insertFunctions); i++) {
        void (*insert)(int*, int, BinarySearchTree*) = insertFunctions[i];

        for (unsigned int j = 0; j < sizeof(ns) / sizeof(*ns); j++) {
            unsigned int size = ns[j];

            int *arr = new int[size];
            fillIncreasing(arr, size);

            clock_t insertion_time = clock();
            insert(arr, size, bst);
            insertion_time = clock() - insertion_time;

            assert(bst->size == size);
            assert(isBST(bst->root));

            shuffle(arr, size);

            clock_t search_time = clock();
            searchTree(bst, arr, size);
            search_time = clock() - search_time;

            shuffle(arr, size);

            deleteElementsFromTree(bst, arr, size);
            assert(bst->size == 0);

            delete bst->root;
            delete bst;
            delete arr;

            std::cout << size << std::endl 
            << insertFunctionsNames[i] << std::endl 
            << (double)insertion_time / CLOCKS_PER_SEC << std::endl 
            << (double)search_time / CLOCKS_PER_SEC << std::endl;
        }
    }
    return 0;
}
