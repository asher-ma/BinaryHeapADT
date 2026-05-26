#ifndef _TASK_
#define _TASK_

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
}

#endif