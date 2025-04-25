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
    std::cout << "5. Highest Response Ratio Next (HRRN)\n";
    std::cout << "6. Multiple Queue Scheduling\n";
    std::cout << "7. Multilevel Feedback Queue Scheduling\n";
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
        displayProcesses(processes, true);
        break;

    case 5:
        HRRN_Scheduling(processes);
        std::cout << "\nAfter HRRN Scheduling:\n";
        displayProcesses(processes);
        break;

    case 6:
    {
        std::vector<std::vector<Process>> queues = {{processes.begin(), processes.begin() + processes.size() / 2},
                                                    {processes.begin() + processes.size() / 2, processes.end()}};
        MultipleQueue_Scheduling(queues);
        std::cout << "\nAfter Multiple Queue Scheduling:\n";
        for (const auto &queue : queues)
            displayProcesses(queue);
        break;
    }

    case 7:
    {
        int num_queues, time_quantum;
        std::cout << "Enter number of queues: ";
        std::cin >> num_queues;
        std::cout << "Enter time quantum: ";
        std::cin >> time_quantum;
        MultilevelFeedbackQueue_Scheduling(processes, num_queues, time_quantum);
        std::cout << "\nAfter Multilevel Feedback Queue Scheduling:\n";
        displayProcesses(processes);
        break;
    }

    default:
        std::cout << "Invalid choice!\n";
        break;
    }

    return 0;
}
