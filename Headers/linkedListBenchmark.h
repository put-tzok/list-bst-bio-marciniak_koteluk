#pragma once

#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <linkedList.h>

void fillIncreasing(int *arr, int size);
void shuffle(int *arr, int size);
void insertElements(LinkedList* list, int* values, int size);
void searchElements(LinkedList* list, int* values, int size); 
void deleteElements(LinkedList* list, int* values, int size);