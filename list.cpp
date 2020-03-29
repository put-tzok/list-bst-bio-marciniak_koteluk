#include <iostream>
#include <linkedList.h>
#include <linkedListBenchmark.h>

unsigned int ns[] = { 10, 100, 1000, 10000, 20000, 30000, 40000, 50000 };

int main() {
    bool shuffleArrayInCurrentIteration[] = { false, true };

    for (unsigned int i = 0; i < sizeof(shuffleArrayInCurrentIteration) / sizeof(*shuffleArrayInCurrentIteration); i++) {
        bool checkShuffle = shuffleArrayInCurrentIteration[i];

        for (unsigned int j = 0; j < sizeof(ns) / sizeof(*ns); j++) {
            LinkedList* list = new LinkedList();
            unsigned int size = ns[j];

            int *arr = new int[size];
            fillIncreasing(arr, size);

            if (checkShuffle) {
                shuffle(arr, size);
            }

            clock_t insertion_time = clock();
            insertElements(list, arr, size);
            insertion_time = clock() - insertion_time;

            shuffle(arr, size);

            clock_t search_time = clock();
            searchElements(list, arr, size);
            search_time = clock() - search_time;

            shuffle(arr, size);

            clock_t deletion_time = clock();
            deleteElements(list, arr, size);
            deletion_time = clock() - deletion_time;

            assert(list->getSize() == 0);
            assert(list->getHead() == NULL);

            delete arr;

            std::cout << size << std::endl 
            << (checkShuffle ? "true" : "false") << std::endl 
            << (double)insertion_time / CLOCKS_PER_SEC << std::endl 
            << (double)search_time / CLOCKS_PER_SEC << std::endl
            << (double)deletion_time / CLOCKS_PER_SEC << std::endl;

            std::cout << std::endl;
        }
    }
    return 0;
}
