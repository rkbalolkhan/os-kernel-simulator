#include "scheduler.h"
#include <algorithm>
#include <queue>
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

// Shortest Job First (SJF) Scheduling
void SJF_Scheduling(std::vector<Process> &processes)
{
    std::sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
              { return a.arrival_time < b.arrival_time || (a.arrival_time == b.arrival_time && a.burst_time < b.burst_time); });

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

// Round Robin (RR) Scheduling
void RoundRobin_Scheduling(std::vector<Process> &processes, int time_quantum)
{
    std::queue<Process *> ready_queue;
    int current_time = 0;

    for (auto &process : processes)
        ready_queue.push(&process);

    while (!ready_queue.empty())
    {
        Process *current_process = ready_queue.front();
        ready_queue.pop();

        if (current_time < current_process->arrival_time)
            current_time = current_process->arrival_time;

        int execution_time = std::min(current_process->burst_time, time_quantum);
        current_process->burst_time -= execution_time;
        current_time += execution_time;

        if (current_process->burst_time > 0)
        {
            ready_queue.push(current_process);
        }
        else
        {
            current_process->turnaround_time = current_time - current_process->arrival_time;
            current_process->waiting_time = current_process->turnaround_time - (current_process->burst_time + execution_time);
        }
    }
}

// Priority Scheduling
void Priority_Scheduling(std::vector<Process> &processes)
{
    std::sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
              { return a.arrival_time < b.arrival_time || (a.arrival_time == b.arrival_time && a.priority < b.priority); });

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

// Multilevel Queue Scheduling
void MultilevelQueue_Scheduling(std::vector<std::vector<Process>> &queues, const std::vector<int> &priorities)
{
    int current_time = 0;

    for (size_t i = 0; i < queues.size(); ++i)
    {
        auto &queue = queues[i];
        int priority = priorities[i];

        std::sort(queue.begin(), queue.end(), [](const Process &a, const Process &b)
                  { return a.arrival_time < b.arrival_time; });

        for (auto &process : queue)
        {
            if (current_time < process.arrival_time)
                current_time = process.arrival_time;

            process.waiting_time = current_time - process.arrival_time;
            process.turnaround_time = process.waiting_time + process.burst_time;
            current_time += process.burst_time;
        }
    }
}
