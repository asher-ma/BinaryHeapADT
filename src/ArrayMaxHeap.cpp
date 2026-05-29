#include "HeapInterface.h"
#include "ArrayMaxHeap.h"
#include <cmath>
#include <iostream>


// Constructors
// -----------------------------------------------------------------------------------------

//Default constructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(bool isMinHeap)
        : items(new ItemType[DEFAULT_CAPACITY]), itemCount(0), maxItems(DEFAULT_CAPACITY), isMinHeap(isMinHeap) {}

// Parameterized contructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize, bool isMinHeap)
        : itemCount(arraySize), maxItems(DEFAULT_CAPACITY), items(new ItemType[DEFAULT_CAPACITY]), isMinHeap(isMinHeap) {
    for (int i = 0; i < arraySize; i++) { // Copy array contents into heap array
        this->items[i] = someArray[i];
    }
    this->heapCreate(); // Reorder contents to obey heap condition
}

// Copy constructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ArrayMaxHeap& other)
        : itemCount(other.itemCount), maxItems(other.maxItems), isMinHeap(other.isMinHeap), items(new ItemType[other.maxItems]) {
    for (int i = 0; i < itemCount; i++) { // Copy other.items contents into new heap array
        this->items[i] = other.items[i];
    }
}

// Destructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {
    delete[] items;
}


// Public methods
// ----------------------------------------------------------------------------------------

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {
    return itemCount;
}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const {
    if (this->isEmpty()) {
        return 0;
    }
    return ceil(std::log2(itemCount+1));
}

template <typename ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const {
    if (this->isEmpty()) {
        throw PrecondViolatedExcep("Attempted to peek into empty heap");
    }
    return items[0];
}

// Adds new data to heap and enforces heap property
template <typename ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {
    if (itemCount == maxItems) {
        return false;
    } else if (this->isEmpty()) {
        items[0] = newData; // Set root to newData
        itemCount++; // Increment itemCount
        return true;
    }
    items[itemCount] = newData; // Add new data to end of heap
    int newDataIndex = itemCount;
    bool inPlace = false;
    while ((newDataIndex > 0) && !inPlace) { // While new data is not inPlace
        int parentIndex = getParentIndex(newDataIndex);
        if (isMinHeap ? items[newDataIndex] >= items[parentIndex] : items[newDataIndex] <= items[parentIndex]) { // If data is smaller than or equal to parent OR opposite for minHeap
            inPlace = true; // It is in place
        } else {
            ItemType temp = items[newDataIndex]; // Replace data with parent (moving it up heap)
            items[newDataIndex] = items[parentIndex];
            items[parentIndex] = temp;
            newDataIndex = parentIndex;
        }
    }
    itemCount++;
    return true;
}

// Removes root from top of heap
template <typename ItemType>
bool ArrayMaxHeap<ItemType>::remove() {
    if (this->isEmpty()) { // Don't attempt remove() on empty heap
        return false;
    }
    items[0] = items[itemCount-1]; // Move last item to front, replacing root
    items[itemCount-1] = ItemType(); // Clear the last element to avoid stale data
    itemCount--; // Shorten itemCount
    heapRebuild(0); // Move smallest item down heap, enforcing heap property
    return true;
}

template <typename ItemType>
void ArrayMaxHeap<ItemType>::clear() {
    for (int i = 0; i < itemCount; i++) { // For each item
        items[i] = ItemType(); // Clear it
    }
    itemCount = 0;
}

// Creates duplicate heap and prints each item while deconstructing it
template <typename ItemType>
void ArrayMaxHeap<ItemType>::printHeap() const {
    ArrayMaxHeap<ItemType> dupeHeap(*this);
    while(!dupeHeap.isEmpty()) { // While heap is not empty
        std::cout << dupeHeap.peekTop(); // Print item
        dupeHeap.remove(); // Remove item
        if (!dupeHeap.isEmpty()) { // If not empty
            std::cout << "  |  "; // Print spacer
        }
    }
    std::cout << std::endl;
}


// Private methods
// ----------------------------------------------------------------------------------------

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {
    return 2*nodeIndex + 1;
}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const {
    return 2*nodeIndex + 2;
}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const {
    return floor((nodeIndex-1)/2);
}

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const {
    if (getLeftChildIndex(nodeIndex) >= itemCount) {
        return true;
    }
    return false;
}

// If isMinHeap: do opposite of below
// If a child is larger than the parent, swap the largest child with parent
// If swap occurs, recursively call heapRebuild on orginal node, moving it down
// heap until it is larger than both children
template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex) {
    int l = getLeftChildIndex(subTreeRootIndex);
    int r = getRightChildIndex(subTreeRootIndex);
    int largest = subTreeRootIndex;

    if (isMinHeap ? l < itemCount && items[l] < items[subTreeRootIndex] : l < itemCount && items[l] > items[subTreeRootIndex]) { // If left child is larger than parent
        largest = l; // Overwrite largest with left child
    }
    if (isMinHeap ? r < itemCount && items[r] < items[largest] : r < itemCount && items[r] > items[largest]) { // If right child is larger than current largest
        largest = r; // Overwrite largest with right child
    }
    if (largest != subTreeRootIndex) { // If largest is not parent
        ItemType temp = items[subTreeRootIndex]; // Swap parent with largest
        items[subTreeRootIndex] = items[largest];
        items[largest] = temp;
        heapRebuild(largest); // Call heapRebuild on node in new location
    }
}

// Ensures items[] member array follows heap property
template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {
    for (int i = itemCount/2-1; i >= 0; i--) { // On upper half of items, from middle to top
        heapRebuild(i); // Call heapRebuild 
    }
}

// End of ArrayMaxHeap.cpp