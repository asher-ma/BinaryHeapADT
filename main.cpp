#include <iostream>
#include <limits>
#include <string>

#include "ArrayMaxHeap.h"
#include "HeapSort.h"
#include "TaskScheduler.h"

void displayMenu() {
    std::cout << "========== HEAP MENU ==========\n";
    std::cout << "1. Build Heap\n";
    std::cout << "2. Insert\n";
    std::cout << "3. Extract Root\n";
    std::cout << "4. Peek Root\n";
    std::cout << "5. Print Heap\n";
    std::cout << "6. Heap Sort\n";
    std::cout << "7. Task Scheduler\n";
    std::cout << "8. Exit\n";
}

int main() {
    ArrayMaxHeap<int> heap;
    bool heapBuilt = false;
    bool running = true;

    while (running) {
        displayMenu();
        std::cout << "Enter choice: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 8.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::cout << "Building heap from array: ";
                int values[7] = {2, 5, 8, 1, 3, 6, 10};
                for (int num : values) {
                    std::cout << num << ", ";
                }
                heap = ArrayMaxHeap<int>(values, 7);
                heapBuilt = true;
                std::cout << "\nHeap built from sample array.\n";
                break;
            }
            case 2: {
                if (!heapBuilt) {
                    std::cout << "Build the heap first (option 1).\n";
                } else {
                    std::cout << "Enter value to insert: ";
                    int value;
                    std::cin >> value;
                    heap.add(value);
                    std::cout << "Inserted " << value << " into heap.\n";
                }
                break;
            }
            case 3: {
                if (heap.isEmpty()) {
                    std::cout << "Heap is empty. Nothing to extract.\n";
                } else {
                    std::cout << "Extracted root: " << heap.peekTop() << "\n";
                    heap.remove();
                }
                break;
            }
            case 4: {
                if (heap.isEmpty()) {
                    std::cout << "Heap is empty. No root to peek.\n";
                } else {
                    std::cout << "Current root: " << heap.peekTop() << "\n";
                }
                break;
            }
            case 5: {
                if (heap.isEmpty()) {
                    std::cout << "Heap is empty. Nothing to print.\n";
                } else {
                    std::cout << "Heap contents (by descending priority): ";
                    heap.printHeap();
                }
                break;
            }
            case 6: {
                int array2[10] = {2, 5, 8, 1, 3, 6, 10, 4, 7, 9};
                std::cout << "\nHeap Sort Demo:\n";
                std::cout << "Unsorted Array: ";
                for (int item : array2) {
                    std::cout << item << " ";
                }
                std::cout << "\nSorting...\n";
                heapSort(array2, 10);
                std::cout << "Sorted Array: ";
                for (int item : array2) {
                    std::cout << item << " ";
                }
                std::cout << "\n";
                break;
            }
            case 7: {
                TaskScheduler<std::string> scheduler;

                std::cout << "\nTask Scheduler Demo:\n";
                scheduler.addTask("Task 1", 10, "Construct UML Diagram");
                scheduler.addTask("Task 2", 5, "Write technical report");
                scheduler.addTask("Task 3", 20, "Finish TaskScheduler implementation");

                scheduler.displayTasks();
                scheduler.peekNextTask();
                scheduler.executeTask();
                scheduler.displayTasks();
                break;
            }
            case 8:
                running = false;
                std::cout << "Exiting.\n";
                break;
            default:
                std::cout << "Please choose a valid option (1-8).\n";
                break;
        }

        std::cout << "\n";
    }

    return 0;
}