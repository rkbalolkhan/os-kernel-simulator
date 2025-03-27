#include "scheduler.h"
#include <algorithm>
#include <iostream>

void FCFS_Scheduling(std::vector<Process> &processes)
{
    std::sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
              { return a.arrival_time < b.arrival_time; });

    int current_time = 0;
    for (auto &process : processes)
    {
        if (current_time < process.arrival_time)
            current_time = process.arrival_time;

        process.waiting_time = current_time - process.arrival_time;
        process.turnaround_time = process.waiting_time + process.burst_time;
        current_time += process.burst_time;
    }
}
