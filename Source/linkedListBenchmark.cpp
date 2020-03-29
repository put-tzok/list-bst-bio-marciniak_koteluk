#include <linkedListBenchmark.h>

void fillIncreasing(int *arr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void shuffle(int *arr, unsigned int size) {
    for (unsigned int i = size - 1; i > 0; i--) {
        int j = rand() % i;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void insertElements(LinkedList* list, int* values, unsigned int size) {
    for (unsigned int k = 0; k < size; k++) {
        Node* insertedNode = list->insertElement(values[k]);
        assert(insertedNode != NULL);
        assert(insertedNode->getValue() == values[k]);
    }
}

void searchElements(LinkedList* list, int* values, unsigned int size) {
    for (unsigned int k = 0; k < size; k++) {
        Node* insertedNode = list->searchElementWithValue(values[k]);
        assert(insertedNode != NULL);
        assert(insertedNode->getValue() == values[k]);
    }
}

void deleteElements(LinkedList* list, int* values, unsigned int size) {
    for (unsigned int k = 0, l = size; k < size; k++, l--) {
        assert(list->getSize() == l);
        list->deleteElementWithValue(values[k]);
    }
}