#include "HeapPriorityQueue.h"
#include "PrecondViolatedException.h"

// Constructor
// -----------------------------------------------------------------------------------------
template <typename ItemType>
HeapPriorityQueue<ItemType>::HeapPriorityQueue() {}


// Public methods
// -----------------------------------------------------------------------------------------

template <typename ItemType>
bool HeapPriorityQueue<ItemType>::isEmpty() const {
    return ArrayMaxHeap<ItemType>::isEmpty();
}

template <typename ItemType>
bool HeapPriorityQueue<ItemType>::add(const ItemType& newEntry) {
    return ArrayMaxHeap<ItemType>::add(newEntry);
}

template <typename ItemType>
bool HeapPriorityQueue<ItemType>::remove() {
    return ArrayMaxHeap<ItemType>::remove();
}

template <typename ItemType>
ItemType HeapPriorityQueue<ItemType>::peek() const {
    return ArrayMaxHeap<ItemType>::peekTop();
}

template <typename ItemType>
void HeapPriorityQueue<ItemType>::printQueue() const {
    ArrayMaxHeap<ItemType>::printHeap();
}