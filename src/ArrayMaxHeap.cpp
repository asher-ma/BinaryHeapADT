#include "../Include/HeapInterface.h"
#include "../Include/ArrayMaxHeap.h"


// Constructors ------------------------------------------------------------------------------------------

//Default constructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
         : items(new ItemType[DEFAULT_CAPACITY]), itemCount(0), maxItems(DEFAULT_CAPACITY) {}

// Parameterized contructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize)
         : items(someArray[]), itemCount(arraySize), maxItems(DEFAULT_CAPACITY) {}

// Destructor
template <typename ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {}


// Public methods -----------------------------------------------------------------------------------------

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const {}

template <typename ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const {}

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {}

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::remove() {}

template <typename ItemType>
void ArrayMaxHeap<ItemType>::clear() {}


// Private methods ----------------------------------------------------------------------------------------

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const {}

template <typename ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const {}

template <typename ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const {}

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex) {}

template <typename ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {}