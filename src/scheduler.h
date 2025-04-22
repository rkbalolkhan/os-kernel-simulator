#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"
#include <vector>

void FCFS_Scheduling(std::vector<Process> &processes);
void SJF_Scheduling(std::vector<Process> &processes);
void RoundRobin_Scheduling(std::vector<Process> &processes, int time_quantum);
void Priority_Scheduling(std::vector<Process> &processes);
void MultilevelQueue_Scheduling(std::vector<std::vector<Process>> &queues, const std::vector<int> &priorities);

#endif
