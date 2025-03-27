# OS Kernel Simulator 🚀
A C++-based OS Kernel Simulator that mimics fundamental process management and CPU scheduling functionalities. This project allows users to create and manage processes while implementing different scheduling algorithms like FCFS, SJF, and Round Robin.

Features 🔹
✅ Process creation with attributes (PID, Burst Time, Arrival Time, Priority)
✅ Implements scheduling algorithms: FCFS, SJF, Round Robin
✅ Simulates process execution with state transitions (NEW → READY → RUNNING → TERMINATED)
✅ Displays execution order, waiting time, and turnaround time
✅ Simple command-line interface (CLI) for interaction

Tech Stack 🛠️
🔹 Language: C++
🔹 Libraries: STL, Threads, Queues
🔹 Version Control: Git & GitHub

Installation & Usage
Clone the repository:

sh
Copy
Edit
git clone https://github.com/your-username/OS-Kernel-Simulator.git
cd OS-Kernel-Simulator
Compile the program:

sh
Copy
Edit
g++ -o kernel_simulator main.cpp process.cpp scheduler.cpp ui.cpp -pthread
./kernel_simulator
Follow the CLI instructions to add and manage processes.

Future Enhancements ✨
🔹 Priority Scheduling & Multilevel Queue Scheduling
🔹 Memory Management (Paging & Segmentation)
🔹 Graphical User Interface (GUI)

Contributing 🤝
Want to improve the simulator? Feel free to fork & contribute! 🚀
