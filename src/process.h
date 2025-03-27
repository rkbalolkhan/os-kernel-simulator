#ifndef PROCESS_H
#define PROCESS_H

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;

    Process(int id, int arrival, int burst);
};

#endif
