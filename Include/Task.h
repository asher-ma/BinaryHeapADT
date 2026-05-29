#ifndef _TASK_
#define _TASK_

#include <iostream>
#include <string>

struct Task {
    std::string id;
    int priority;
    std::string description;

    bool operator>(const Task& other) const {
        return priority > other.priority;
    }
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
    bool operator==(const Task& other) const {
        return priority == other.priority;
    }
};

// iostream operator for printing
std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << "[" << task.id << ", Priority: " << task.priority << ", " << task.description << "]";
    return os;
}

#endif