/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Heap class for Food in Wildlife Simulation
 * */

#include "Food.h"

#ifndef INC_2023_HEAP_H
#define INC_2023_HEAP_H

const int MAX_HEAP = 31;

class Heap {
public:
    Heap();

    Food getTop();
    bool heapIsEmpty() const;
    void heapInsert(const Food& newItem);
    void heapDelete(Food& rootItem);

protected:
    void heapRebuild(int root);

private:
    Food items[MAX_HEAP];
    int size;

    // true if second > first, false if first > second
    bool compare(int firstIndex, int secondIndex);

};

#endif //INC_2023_HEAP_H
