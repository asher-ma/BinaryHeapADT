#ifndef _TASK_SCHEDULER_
#define _TASK_SCHEDULER_

#include "HeapPriorityQueue.h"
#include "Task.h"

#include <string>

template <class ItemType>
class TaskScheduler : private HeapPriorityQueue<ItemType> {
    private:
        HeapPriorityQueue<Task> taskQueue;
    public:
        TaskScheduler();

        bool addTask(const std::string& taskId, int priority, const std::string taskDesc);
        void executeTask() ;
        void peekNextTask() const ;
        void displayTasks() const ;
};

#include "../src/TaskScheduler.cpp"

#endif