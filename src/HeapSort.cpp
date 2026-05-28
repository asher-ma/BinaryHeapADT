#include "HeapSort.h"
#include "ArrayMaxHeap.h"

template <typename ItemType>
void heapSort(ItemType someArray[], const int arraySize, bool isMinHeap) {
    ArrayMaxHeap<ItemType> heap(someArray, arraySize, isMinHeap);
    for (int i = arraySize - 1; i >= 0; i--) { // For each item (from back to front)
        someArray[i] = heap.peekTop(); // Overwrite coresponding position in given array
        heap.remove(); // Remove it from heap
    }
}