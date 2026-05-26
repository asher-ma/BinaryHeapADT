#ifndef _TASK_SCHEDULER_
#define _TASK_SCHEDULER_

#include "HeapPriorityQueue.h"

template <class ItemType>
class TaskScheduler : private HeapPriorityQueue<ItemType> {
    public:
        TaskScheduler();

        bool addTask(const ItemType& newTask) ;
        bool executeTask() ;
        ItemType peekNextTask() const ;
        void displayTasks() const ;
}

#include "../src/TaskScheduler.cpp"

#endif