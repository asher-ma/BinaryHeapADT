#ifndef _TASK_SCHEDULER_
#define _TASK_SCHEDULER_

#include "HeapPriorityQueue.h"

template <class ItemType>
class TaskScheduler : private HeapPriorityQueue<ItemType> {
    private:
        HeapPriorityQueue<Task> taskQueue;
    public:
        TaskScheduler();

        bool addTask(const std::string taskId, const int priority, const std::string taskDesc) ;
        bool executeTask() ;
        ItemType peekNextTask() const ;
        void displayTasks() const ;
}

#include "../src/TaskScheduler.cpp"

#endif