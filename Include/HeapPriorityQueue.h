#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"
#include "PrecondViolatedException.h"

template < class ItemType>
class HeapPriorityQueue : public PriorityQueueInterface<ItemType>, // you may not really need the the queue interface, though. feel free to rethink.
                            private ArrayMaxHeap<ItemType>{
    public :
        HeapPriorityQueue();

        bool isEmpty() const;
        bool add( const ItemType& newEntry);
        bool remove();

        ItemType peek() const throw (PrecondViolatedExcep);

    }; // end Heap_PriorityQueue

#include "../src/HeapPriorityQueue.cpp"

#endif