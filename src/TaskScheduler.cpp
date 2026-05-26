#include "TaskScheduler.h"
#include <iostream>


// Constructor
// -----------------------------------------------------------------------------------------

template <typename ItemType>
TaskScheduler<ItemType>::TaskScheduler() {}

// Public Methods
// -----------------------------------------------------------------------------------------

template <typename ItemType>
bool TaskScheduler<ItemType>::addTask(const ItemType& newTask) {}

template <typename ItemType>
bool TaskScheduler<ItemType>::executeTask() {}

template <typename ItemType>
ItemType TaskScheduler<ItemType>::peekNextTask() const {}

template <typename ItemType>
void TaskScheduler<ItemType>::displayTasks() const {}