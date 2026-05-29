#include <iostream>
#include <vector>

#include "HeapSort.h"

int main (){
    // Make array
    int array[7] = {2, 5, 8, 1, 3, 6, 10};
    std::cout << "Array: ";
    for (int x : array) {
        std::cout << x << " ";
    }

    // Heap it
    std::cout << "\nBuilding heap...\n";
    ArrayMaxHeap<int> heap{array, 7};

    // Popping
    std::cout << "\nDeconstructing heap:\n";
    while (!heap.isEmpty()) {
        std::cout << heap.peekTop() << " ";
        heap.remove();
    }
    std::cout << "\n";

    // Clear
    std::cout << "\nClearing Heap...\n";
    heap.clear();
    std::cout << "isEmpty: " << (heap.isEmpty() ? "true" : "false") << "\n";

    
    // Testing Heapsort
    // ---------------------------------------------------------------------------------------------
    std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n" <<
            "Testing Heapsort\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    // Make unsorted array
    int array2[10] = {2, 5, 8, 1, 3, 6, 10, 4, 7, 9};
    std::cout << "\nUnsorted Array: ";
    for (int item : array2) {
        std::cout << item << " ";
    }

    // Sort array
    std::cout << "\nSorting...";
    heapSort(array2, 10);

    // Print sorted array
    std::cout << "\nSorted Array: ";
    for (int item : array2) {
        std::cout << item << " ";
    }
    std::cout << "\n";
    return 0;
}