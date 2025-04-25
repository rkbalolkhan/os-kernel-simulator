#include "ui.h"
#include <iostream>

void displayProcesses(const std::vector<Process> &processes, bool show_priority)
{
    if (show_priority)
    {
        std::cout << "PID\tArrival\tBurst\tPriority\tWaiting\tTurnaround\tCompletion\n";
        for (const auto &p : processes)
        {
            std::cout << p.pid << "\t" << p.arrival_time << "\t"
                      << p.burst_time << "\t" << p.priority << "\t\t"
                      << p.waiting_time << "\t" << p.turnaround_time << "\t \t" << p.completion_time << "\n";
        }
        return;
    }
    std::cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for (const auto &p : processes)
    {
        std::cout << p.pid << "\t" << p.arrival_time << "\t"
                  << p.burst_time << "\t" << p.waiting_time << "\t"
                  << p.turnaround_time << "\t \t" << p.completion_time << "\n";
    }
}
