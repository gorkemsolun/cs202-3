/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Heap class for Food in Wildlife Simulation
 * */

#include "Food.h"
#include <bits/stdc++.h>
using namespace std;

#ifndef INC_2023_HEAP_H
#define INC_2023_HEAP_H

const int MAX_HEAP = 31;

class Heap {
public:
    Heap();
    Heap(string type);

    Food getTop();
    bool heapIsEmpty() const;
    void heapInsert(const Food& newItem);
    void heapDelete();

protected:
    void heapRebuild(int root);

private:
    Food items[MAX_HEAP];
    int size;
    string type; // "QUALITY", "TIME" default: "QUALITY"

    // For QUALITY: true if second > first, false if first > second
    // For TIME:
    bool compare(int firstIndex, int secondIndex);

};

#endif //INC_2023_HEAP_H
