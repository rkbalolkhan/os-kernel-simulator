#ifndef PROCESS_H
#define PROCESS_H

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int priority;

    Process(int id, int arrival, int burst, int prio = 0);
};

#endif
