#include <iostream>
#include <linkedList.h>
#include <linkedListBenchmark.h>

unsigned int ns[] = { 10, /* TODO: fill values which will be used as lists' sizes */ };

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

            deleteElements(list, arr, size);
            assert(list->getSize() == 0);
            assert(list->getHead() == NULL);

            delete arr;

            std::cout << size << std::endl 
            << (checkShuffle ? "true" : "false") << std::endl 
            << (double)insertion_time / CLOCKS_PER_SEC << std::endl << (double)search_time / CLOCKS_PER_SEC << std::endl;
        }
    }
    return 0;
}
