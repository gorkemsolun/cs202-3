/*
 * Görkem Kadir Solun
 * 22003214
 * 202-1
 * HW3
 * Heap class for Food in Wildlife Simulation
 * */

#include "Heap.h"

Heap::Heap() {
    this->size = 0;
}

bool Heap::heapIsEmpty() const {
    return this->size == 0;
}

void Heap::heapInsert(const Food &newItem) {
    if (this->size >= MAX_HEAP) {
        cout << "HeapException: Heap full" << endl;
    }
    this->items[this->size] = newItem;

    int place = this->size;
    int parent = (place - 1) / 2;
    while ((place > 0) && (compare(parent, place))) {
        Food temp = this->items[parent];
        this->items[parent] = this->items[place];
        this->items[place] = temp;
        place = parent;
        parent = (place - 1) / 2;
    }
    this->size++;
}

void Heap::heapDelete() {
    if (heapIsEmpty()){
        cout << "HeapException: Heap empty" << endl;
    }
    else {
        this->items[0] = this->items[--this->size];
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;
    if (child < this->size) {
        int rightChild = child + 1;

        if ((rightChild < this->size) && compare(child, rightChild)) {
            child = rightChild;
        }

        if (compare(root, child)) {
            Food temp = this->items[root];
            this->items[root] = this->items[child];
            this->items[child] = temp;

            heapRebuild(child);
        }
    }
}

/*
 * compares the qualities
 * true if second > first, false if first > second
 * if equal, compare the ids
 * if seconds id is lower than firsts true, else false
 */
bool Heap::compare(int firstIndex, int secondIndex) {
    if (this->items[firstIndex].getQuality() > this->items[secondIndex].getQuality()) {
        return false;
    } else if (this->items[firstIndex].getQuality() < this->items[secondIndex].getQuality()) {
        return true;
    } else {
        if (this->items[firstIndex].getID() > this->items[secondIndex].getID()) {
            return true;
        } else {
            return false;
        }
    }
}

Food Heap::getTop() {
    return this->items[0];
}
