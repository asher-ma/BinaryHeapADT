#include "TaskScheduler.h"
#include "Task.h"
#include <iostream>


// Constructor
// -----------------------------------------------------------------------------------------

template <typename ItemType>
TaskScheduler<ItemType>::TaskScheduler() {}


// Public Methods
// -----------------------------------------------------------------------------------------

// Creates task object and adds it to taskQueue
template <typename ItemType>
void TaskScheduler<ItemType>::addTask(const std::string taskId, const int priority, const std::string taskDesc) {
    Task currentTask;
    currentTask.id = taskId;
    currentTask.description = taskDesc;
    currentTask.priority = priority;
    return taskQueue.add(currentTask);
}

// Print task id to demonstrate function
template <typename ItemType>
void TaskScheduler<ItemType>::executeTask() {
    std::cout << "Executing task: " << taskQueue.peek().id;
    taskQueue.remove();
}

// Print next tasks attributes
template <typename ItemType>
void TaskScheduler<ItemType>::peekNextTask() const {
    std::cout << "Next task: " << taskQueue.peek();
}

template <typename ItemType>
void TaskScheduler<ItemType>::displayTasks() const {}