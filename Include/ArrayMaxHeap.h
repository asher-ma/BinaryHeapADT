#ifndef _ARRAY_MAX_HEAP_H_
#define _ARRAY_MAX_HEAP_H_

#include "HeapInterface.h"
#include "PrecondViolatedException.h"


template < class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType> {

    private :
        static const int ROOT_INDEX = 0; // Helps with readability
        static const int DEFAULT_CAPACITY = 21; // Small capacity to test for a full heap
        ItemType* items; // Array of heap items
        int itemCount; // Current count of heap items
        int maxItems; // Maximum capacity of the heap
        bool isMinHeap; // Configures if heap is max or min
        
        int getLeftChildIndex(const int nodeIndex) const;
        int getRightChildIndex(int nodeIndex) const;
        int getParentIndex(int nodeIndex) const;
        bool isLeaf(int nodeIndex) const;
        void heapRebuild(int subTreeRootIndex);
        void maxHeapRebuild(int subTreeRootIndex);
        void minHeapRebuild(int subTreeRootIndex);
        void heapCreate();

    public :
        ArrayMaxHeap(bool isMinHeap = false); // Constructors default to maxHeap
        ArrayMaxHeap(const ItemType someArray[], const int arraySize, bool isMinHeap = false);
        virtual ~ArrayMaxHeap();

        // HeapInterface Public Methods:
        bool isEmpty() const ;
        int getNumberOfNodes() const ;
        int getHeight() const ;
        ItemType peekTop() const ; // throw (PrecondViolatedExcep);
        bool add(const ItemType& newData);
        bool remove();
        void clear();
}; // end ArrayMaxHeap

#include "../src/ArrayMaxHeap.cpp"

#endif