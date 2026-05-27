#include "TaskScheduler.h"
#include "Task.h"
#include <iostream>


// Constructor
// -----------------------------------------------------------------------------------------

template <typename ItemType>
TaskScheduler<ItemType>::TaskScheduler() {}

// Public Methods
// -----------------------------------------------------------------------------------------

template <typename ItemType>
bool TaskScheduler<ItemType>::addTask(const string taskId, const string taskDesc, const int priority) {
    Task currentTask;
    currentTask.id = taskId;
    currentTask.description = taskDesc;
    currentTask.priority = priority;
    return ArrayMaxHeap<Task>::add(currentTask);
}

template <typename ItemType>
bool TaskScheduler<ItemType>::executeTask() {}

template <typename ItemType>
ItemType TaskScheduler<ItemType>::peekNextTask() const {}

template <typename ItemType>
void TaskScheduler<ItemType>::displayTasks() const {}