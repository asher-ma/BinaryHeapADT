#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "ArrayMaxHeap.h"

template < class ItemType>
class HeapPriorityQueue : private ArrayMaxHeap<ItemType>{
    public :
        HeapPriorityQueue();

        bool isEmpty() const;
        bool add( const ItemType& newEntry);
        bool remove();

        ItemType peek() const; // throw (PrecondViolatedExcep);

        void printQueue() const;
    }; // end HeapPriorityQueue

#include "../src/HeapPriorityQueue.cpp"

#endif