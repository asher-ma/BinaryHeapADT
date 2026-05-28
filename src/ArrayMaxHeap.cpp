#include "HeapInterface.h"
#include "ArrayMaxHeap.h"
#include <cmath>


// Constructors
// -----------------------------------------------------------------------------------------

//Default constructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(bool isMinHeap)
        : items(new ItemType[DEFAULT_CAPACITY]), itemCount(0), maxItems(DEFAULT_CAPACITY), isMinHeap(isMinHeap) {}

// Parameterized contructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize, bool isMinHeap)
        : itemCount(arraySize), maxItems(DEFAULT_CAPACITY), items(new ItemType[maxItems]), isMinHeap(isMinHeap) {
    for (int i = 0; i < arraySize; i++) { // Copy array contents into heap array
        this->items[i] = someArray[i];
    }
    this->heapCreate(); // Reorder contents to obey heap condition
}

// Destructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {}


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
        if (items[newDataIndex] <= items[parentIndex]) { // If data is smaller than or equal to parent
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


// Private methods
// ----------------------------------------------------------------------------------------

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {
    return 2*nodeIndex;
}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const {
    return 2*nodeIndex + 1;
}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const {
    return floor(nodeIndex/2);
}

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const {
    if (getLeftChildIndex(nodeIndex) >= itemCount) {
        return true;
    }
    return false;
}

// Decides which way to rebuild heap depending on isMinHeap value
template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex) {
    if (isMinHeap == true) {
        minHeapRebuild(subTreeRootIndex);
    } else {
        maxHeapRebuild(subTreeRootIndex);
    }
}

// If a child is larger than the parent, swap the largest child with parent
// If swap occurs, recursively call heapRebuild on orginal node, moving it down
// heap until it is larger than both children
template <typename ItemType>
void ArrayMaxHeap<ItemType>::maxHeapRebuild(int subTreeRootIndex) {
    int l = getLeftChildIndex(subTreeRootIndex);
    int r = getRightChildIndex(subTreeRootIndex);
    int largest = subTreeRootIndex;

    if (l <= itemCount && items[l] > items[subTreeRootIndex]) { // If left child is larger than parent
        largest = l; // Overwrite largest with left child
    }
    if (r <= itemCount && items[r] > items[largest]) { // If right child is larger than current largest
        largest = r; // Overwrite largest with right child
    }
    if (largest != subTreeRootIndex) { // If largest is not parent
        int temp = items[subTreeRootIndex]; // Swap parent with largest // TODO: Use ItemType instead of int(?)
        items[subTreeRootIndex] = items[largest];
        items[largest] = temp;
        heapRebuild(largest); // Call heapRebuild on node in new location
    }
}

// If a child is smaller than the parent, swap the smallest child with parent
// If swap occurs, recursively call heapRebuild on orginal node, moving it down
// heap until it is smaller than both children
template <typename ItemType>
void ArrayMaxHeap<ItemType>::minHeapRebuild(int subTreeRootIndex) {
    int l = getLeftChildIndex(subTreeRootIndex);
    int r = getRightChildIndex(subTreeRootIndex);
    int smallest = subTreeRootIndex;

    if (l <= itemCount && items[l] < items[subTreeRootIndex]) { // If left child is smaller than parent
        smallest = l; // Overwrite smallest with left child
    }
    if (r <= itemCount && items[r] < items[smallest]) { // If right child is smaller than current smallest
        smallest = r; // Overwrite smallest with right child
    }
    if (smallest != subTreeRootIndex) { // If smallest is not parent
        int temp = items[subTreeRootIndex]; // Swap parent with smallest // TODO: Use ItemType instead of int(?)
        items[subTreeRootIndex] = items[smallest];
        items[smallest] = temp;
        heapRebuild(smallest); // Call heapRebuild on node in new location
    }
}

// Ensures items[] member array follows heap property
template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {
    for (int i = itemCount/2; i >= 0; i--) { // On upper half of items, from middle to top
        heapRebuild(i); // Call heapRebuild 
    }
}

// End of ArrayMaxHeap.cpp