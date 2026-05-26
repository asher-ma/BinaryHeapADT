#include "../Include/HeapInterface.h"
#include "../Include/ArrayMaxHeap.h"
#include <cmath>


// Constructors ------------------------------------------------------------------------------------------

//Default constructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
        : items(new ItemType[DEFAULT_CAPACITY]), itemCount(0), maxItems(DEFAULT_CAPACITY) {}

// Parameterized contructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize)
        : itemCount(arraySize), maxItems(DEFAULT_CAPACITY), items(new ItemType[maxItems]) {
    // Copy array contents into heap array
    for (int i = 0; i < arraySize; i++) {
        this->items[i] = someArray[i];
    }
    // Reorder contents to obey heap condition
    this->heapCreate();
}

// Destructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {}


// Public methods -----------------------------------------------------------------------------------------

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

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {}

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::remove() {}

template <typename ItemType>
void ArrayMaxHeap<ItemType>::clear() {}


// Private methods ----------------------------------------------------------------------------------------

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

// If a child is larger than the parent, swap the largest child with parent
// If swap occurs, recursively call heapRebuild on orginal node, moving it down
// heap until it is larger than both children
template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex) {
    int l = getLeftChildIndex(subTreeRootIndex);
    int r = getRightChildIndex(subTreeRootIndex);
    int largest = subTreeRootIndex;

    // If left child is larger than parent
    if (l <= itemCount && items[l] > items[subTreeRootIndex]) {
        // Overwrite largest with left child
        largest = l;
    }
    // If right child is larger than left child
    if (r <= itemCount && items[r] > items[largest]) {
        // Overwrite largest with right child
        largest = r;
    }
    // If largest is not parent
    if (largest != subTreeRootIndex) {
        // Swap parent with largest
        int temp = items[subTreeRootIndex]; // TODO: Use ItemType instead of int(?)
        items[subTreeRootIndex] = items[largest];
        items[largest] = temp;
        // Call heapRebuild on node in new location
        heapRebuild(largest);
    }
}

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {}