#include "HeapSort.h"
#include "ArrayMaxHeap.h"

template <typename ItemType>
void HeapSort<ItemType>::heapSort(ItemType someArray[], const int arraySize) {
    ArrayMaxHeap<ItemType> heap(someArray, arraySize);
    for (int i = arraySize - 1; i >= 0; i--) { // For each item (from back to front)
        someArray[i] = heap.peekTop(); // Overwrite coresponding position in given array
        heap.remove(); // Remove it from heap
    }
}