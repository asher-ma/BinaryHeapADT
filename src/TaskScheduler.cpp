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
void TaskScheduler<ItemType>::addTask(const std::string taskId, const int priority, const std::string taskDesc) {
    Task currentTask;
    currentTask.id = taskId;
    currentTask.description = taskDesc;
    currentTask.priority = priority;
    return taskQueue.add(currentTask);
}

template <typename ItemType>
void TaskScheduler<ItemType>::executeTask() {}

template <typename ItemType>
void TaskScheduler<ItemType>::peekNextTask() const {}

template <typename ItemType>
void TaskScheduler<ItemType>::displayTasks() const {}