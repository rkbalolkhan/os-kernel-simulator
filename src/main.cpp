#include "process.h"
#include "scheduler.h"
#include "ui.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Process> processes = {
        {1, 0, 5}, {2, 1, 3}, {3, 2, 8}, {4, 3, 6}};

    std::cout << "Before Scheduling:\n";
    displayProcesses(processes);

    FCFS_Scheduling(processes);

    std::cout << "\nAfter Scheduling:\n";
    displayProcesses(processes);

    return 0;
}
