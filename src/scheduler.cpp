#include "scheduler.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <climits>

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
        process.completion_time = current_time + process.burst_time;
        current_time += process.burst_time;
    }
}

void SJF_Scheduling(std::vector<Process> &processes)
{
    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    std::vector<bool> is_done(n, false);

    while (completed < n)
    {
        int idx = -1;
        int min_burst = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!is_done[i] && processes[i].arrival_time <= current_time && processes[i].burst_time < min_burst)
            {
                min_burst = processes[i].burst_time;
                idx = i;
            }
        }

        if (idx == -1)
        {
            current_time++;
            continue;
        }

        Process &p = processes[idx];
        p.waiting_time = current_time - p.arrival_time;
        p.turnaround_time = p.waiting_time + p.burst_time;
        p.completion_time = current_time + p.burst_time;

        current_time += p.burst_time;
        is_done[idx] = true;
        completed++;
    }
}

void RoundRobin_Scheduling(std::vector<Process> &processes, int time_quantum)
{
    std::queue<Process *> ready_queue;
    int current_time = 0;
    int n = processes.size();
    std::vector<int> remaining_burst(n);
    std::vector<bool> in_queue(n, false);
    int completed = 0;

    for (int i = 0; i < n; i++)
    {
        remaining_burst[i] = processes[i].burst_time;
    }

    std::sort(processes.begin(), processes.end(), [](const Process &a, const Process &b)
              { return a.arrival_time < b.arrival_time; });

    int index = 0;

    while (index < n && processes[index].arrival_time <= current_time)
    {
        ready_queue.push(&processes[index]);
        in_queue[index] = true;
        index++;
    }

    while (!ready_queue.empty())
    {
        Process *current_process = ready_queue.front();
        ready_queue.pop();

        int i = std::distance(&processes[0], current_process);

        if (current_time < current_process->arrival_time)
            current_time = current_process->arrival_time;

        int exec_time = std::min(remaining_burst[i], time_quantum);
        remaining_burst[i] -= exec_time;
        current_time += exec_time;

        while (index < n && processes[index].arrival_time <= current_time)
        {
            if (!in_queue[index])
            {
                ready_queue.push(&processes[index]);
                in_queue[index] = true;
            }
            index++;
        }

        if (remaining_burst[i] > 0)
        {
            ready_queue.push(current_process);
        }
        else
        {
            current_process->completion_time = current_time;
            current_process->turnaround_time = current_time - current_process->arrival_time;
            current_process->waiting_time = current_process->turnaround_time - processes[i].burst_time;
            completed++;
        }
    }
}

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
        process.completion_time = current_time + process.burst_time;
        current_time += process.burst_time;
    }
}

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
            process.completion_time = current_time + process.burst_time; 
            current_time += process.burst_time;
        }
    }
}

void HRRN_Scheduling(std::vector<Process> &processes)
{
    int n = processes.size();
    int current_time = 0;
    int completed = 0;
    std::vector<bool> is_done(n, false);

    while (completed < n)
    {
        int idx = -1;
        double max_response_ratio = -1;

        for (int i = 0; i < n; i++)
        {
            if (!is_done[i] && processes[i].arrival_time <= current_time)
            {
                double response_ratio = (double)(current_time - processes[i].arrival_time + processes[i].burst_time) / processes[i].burst_time;
                if (response_ratio > max_response_ratio)
                {
                    max_response_ratio = response_ratio;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            current_time++;
            continue;
        }

        Process &p = processes[idx];
        p.waiting_time = current_time - p.arrival_time;
        p.turnaround_time = p.waiting_time + p.burst_time;
        p.completion_time = current_time + p.burst_time;

        current_time += p.burst_time;
        is_done[idx] = true;
        completed++;
    }
}

void MultipleQueue_Scheduling(std::vector<std::vector<Process>> &queues)
{
    int current_time = 0;

    for (auto &queue : queues)
    {
        std::sort(queue.begin(), queue.end(), [](const Process &a, const Process &b)
                  { return a.arrival_time < b.arrival_time; });

        for (auto &process : queue)
        {
            if (current_time < process.arrival_time)
                current_time = process.arrival_time;

            process.waiting_time = current_time - process.arrival_time;
            process.turnaround_time = process.waiting_time + process.burst_time;
            process.completion_time = current_time + process.burst_time;
            current_time += process.burst_time;
        }
    }
}

void MultilevelFeedbackQueue_Scheduling(std::vector<Process> &processes, int num_queues, int time_quantum)
{
    std::vector<std::queue<Process *>> queues(num_queues); 
    std::vector<int> remaining_burst(processes.size());    
    int current_time = 0;
    int completed = 0;

    for (int i = 0; i < processes.size(); i++)
    {
        remaining_burst[i] = processes[i].burst_time;
    }

    while (completed < processes.size())
    {
        for (int q = 0; q < num_queues; q++)
        {
            while (!queues[q].empty())
            {
                Process *current_process = queues[q].front();
                queues[q].pop();

                int idx = std::distance(&processes[0], current_process);
                int exec_time = std::min(remaining_burst[idx], time_quantum * (q + 1));
                remaining_burst[idx] -= exec_time;
                current_time += exec_time;

                if (remaining_burst[idx] > 0)
                {
                    if (q + 1 < num_queues)
                        queues[q + 1].push(current_process);
                    else
                        queues[q].push(current_process); 
                }
                else
                {
                    current_process->completion_time = current_time;
                    current_process->turnaround_time = current_time - current_process->arrival_time;
                    current_process->waiting_time = current_process->turnaround_time - current_process->burst_time;
                    completed++;
                }
            }
        }

        for (auto &process : processes)
        {
            int idx = std::distance(&processes[0], &process);
            if (process.arrival_time <= current_time && remaining_burst[idx] > 0)
            {
                bool already_in_queue = false;
                for (int q = 0; q < num_queues; q++)
                {
                    bool already_in_queue = false;
                    std::queue<Process *> temp_queue = queues[q];
                    while (!temp_queue.empty())
                    {
                        if (temp_queue.front() == &process)
                        {
                            already_in_queue = true;
                            break;
                        }
                        temp_queue.pop();
                    }
                    if (already_in_queue)
                    {
                        already_in_queue = true;
                        break;
                    }
                }
                if (!already_in_queue)
                {
                    queues[0].push(&process);
                }
            }
        }
    }
}
