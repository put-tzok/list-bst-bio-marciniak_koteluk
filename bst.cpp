#include "Headers/binaryTree.h"
#include "Headers/binaryTreeBenchmark.h"
#include <fstream>
#include <iostream>
#include <cstdio>

unsigned int ns[] = { 10, 100, 1000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

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

            FILE* data;
            data= fopen("./data.txt", "a");
            fprintf(data, "%u\t%f\t%f\n", size, (double)insertion_time / CLOCKS_PER_SEC, (double)search_time / CLOCKS_PER_SEC);
            printf("%u\t%f\t%f\n", size, (double)insertion_time / CLOCKS_PER_SEC, (double)search_time / CLOCKS_PER_SEC);
            fclose(data);
        }
    }
    return 0;
}
