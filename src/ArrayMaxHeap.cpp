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
    for (int i = 0; i < arraySize; i++) {
        this->items[i] = someArray[i];
    }
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
    if (itemCount == 0) {
        return 0;
    }
    return ceil(std::log2(itemCount+1));
}

template <typename ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const {
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

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex) {}

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {}