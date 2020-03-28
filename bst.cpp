#include "Headers/binaryTree.h"
#include "Headers/binaryTreeBenchmark.h"

unsigned int ns[] = { 10, /* TODO: fill values which will be used as lists' sizes */ };

void insertBinary(int *arr, unsigned int size, BinarySearchTree* bst) {
    return;
}

std::string insertFunctionsNames[] = { "Increasing", "Random", "Binary" };
void (*insertFunctions[])(int*, unsigned int, BinarySearchTree*) = { insertIncreasing, insertRandom, insertBinary };

int main() {
    for (unsigned int i = 0; i < sizeof(insertFunctions) / sizeof(*insertFunctions); i++) {
        void (*insert)(int*, unsigned int, BinarySearchTree*) = insertFunctions[i];

        for (unsigned int j = 0; j < sizeof(ns) / sizeof(*ns); j++) {
            BinarySearchTree* bst = new BinarySearchTree();
            
            unsigned int size = ns[j];

            int *arr = new int[size];
            fillIncreasing(arr, size);

            clock_t insertion_time = clock();
            insert(arr, size, bst);
            insertion_time = clock() - insertion_time;

            assert(bst->getSize() == size);
            assert(isBST(bst->getRoot()));

            shuffle(arr, size);

            clock_t search_time = clock();
            searchTree(bst, arr, size);
            search_time = clock() - search_time;

            shuffle(arr, size);

            deleteElementsFromTree(bst, arr, size);
            assert(bst->getSize() == 0);

            delete bst->getRoot();
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
