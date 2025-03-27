#include "ui.h"
#include <iostream>

void displayProcesses(const std::vector<Process> &processes)
{
    std::cout << "PID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto &p : processes)
    {
        std::cout << p.pid << "\t" << p.arrival_time << "\t"
                  << p.burst_time << "\t" << p.waiting_time << "\t"
                  << p.turnaround_time << "\n";
    }
}
