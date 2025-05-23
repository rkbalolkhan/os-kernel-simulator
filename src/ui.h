#ifndef UI_H
#define UI_H

#include "process.h"
#include <vector>

void displayProcesses(const std::vector<Process> &processes, bool show_priority = false);

#endif
