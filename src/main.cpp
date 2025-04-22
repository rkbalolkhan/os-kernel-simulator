#include "process.h"
#include "scheduler.h"
#include "ui.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Process> processes = {
        {1, 0, 5, 2}, {2, 1, 3, 1}, {3, 2, 8, 3}, {4, 3, 6, 2}};

    std::cout << "Before Scheduling:\n";
    displayProcesses(processes);

    // FCFS Scheduling
    FCFS_Scheduling(processes);
    std::cout << "\nAfter FCFS Scheduling:\n";
    displayProcesses(processes);

    // SJF Scheduling
    SJF_Scheduling(processes);
    std::cout << "\nAfter SJF Scheduling:\n";
    displayProcesses(processes);

    // Round Robin Scheduling
    RoundRobin_Scheduling(processes, 2);
    std::cout << "\nAfter Round Robin Scheduling:\n";
    displayProcesses(processes);

    // Priority Scheduling
    Priority_Scheduling(processes);
    std::cout << "\nAfter Priority Scheduling:\n";
    displayProcesses(processes);

    return 0;
}
