#include "process.h"
#include "scheduler.h"
#include "ui.h"
#include <iostream>
#include <vector>

void inputProcesses(std::vector<Process> &processes)
{
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int pid, arrival, burst, priority;
        std::cout << "Enter Process ID, Arrival Time, Burst Time, and Priority for Process " << i + 1 << ": ";
        std::cin >> pid >> arrival >> burst >> priority;
        processes.emplace_back(pid, arrival, burst, priority);
    }
}

int main()
{
    std::vector<Process> processes;
    inputProcesses(processes);

    std::cout << "\nSelect Scheduling Algorithm:\n";
    std::cout << "1. First Come First Serve (FCFS)\n";
    std::cout << "2. Shortest Job First (SJF)\n";
    std::cout << "3. Round Robin (RR)\n";
    std::cout << "4. Priority Scheduling\n";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        FCFS_Scheduling(processes);
        std::cout << "\nAfter FCFS Scheduling:\n";
        displayProcesses(processes);
        break;

    case 2:
        SJF_Scheduling(processes);
        std::cout << "\nAfter SJF Scheduling:\n";
        displayProcesses(processes);
        break;

    case 3:
    {
        int time_quantum;
        std::cout << "Enter Time Quantum for Round Robin: ";
        std::cin >> time_quantum;
        RoundRobin_Scheduling(processes, time_quantum);
        std::cout << "\nAfter Round Robin Scheduling:\n";
        displayProcesses(processes);
        break;
    }

    case 4:
        Priority_Scheduling(processes);
        std::cout << "\nAfter Priority Scheduling:\n";
        displayProcesses(processes);
        break;

    default:
        std::cout << "Invalid choice!\n";
        break;
    }

    return 0;
}
