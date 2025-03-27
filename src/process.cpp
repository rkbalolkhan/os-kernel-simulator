#include "process.h"

Process::Process(int id, int arrival, int burst)
    : pid(id), arrival_time(arrival), burst_time(burst), waiting_time(0), turnaround_time(0) {}
