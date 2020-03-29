#pragma once

#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <linkedList.h>

void fillIncreasing(int *arr, unsigned int size);
void shuffle(int *arr, unsigned int size);
void insertElements(LinkedList* list, int* values, unsigned int size);
void searchElements(LinkedList* list, int* values, unsigned int size); 
void deleteElements(LinkedList* list, int* values, unsigned int size);