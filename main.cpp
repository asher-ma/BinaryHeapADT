#include <iostream>
#include <vector>

#include "ArrayMaxHeap.h"

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
    return 0;
}