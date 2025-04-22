# 🖥️ OS Kernel Simulator
## 📌 Project Overview
The OS Kernel Simulator is a C++-based project that simulates essential operating system functionalities, including: \n
⋅⋅* 🟢 Process Management – Handles process creation, execution, and state transitions. \n
⋅⋅* 🔵 CPU Scheduling – Implements multiple scheduling algorithms. \n
⋅⋅* 🔴 Performance Analysis – Displays process execution order, waiting time, and turnaround time. \n

## 🚀 Features
### 🛠️ Process Management
- ✔️ Uses Process Control Block (PCB) to store process details. \n
- ✔️ Simulates state transitions: \n
        `NEW → READY → RUNNING → TERMINATED` \n

### 🎯 CPU Scheduling Algorithms
- ✔️ First Come First Serve (FCFS) \n
- ✔️ Shortest Job First (SJF) \n
- ✔️ Round Robin (RR) \n

### 📊 Execution & Statistics
- ✔️ Simulates real-time execution using sleep(). \n
- ✔️ Displays waiting time, turnaround time, and CPU utilization. \n

## ⚙️ Technology Stack

|   Technology  |     Usage     |
| ------------- |:-------------:|
| 🖥️ C++ | Core programming language |
| 📚 STL (Standard Template Library) | Data structures & algorithms |
| 🔄 Threads & Queues | Process scheduling simulation |
| 🔧 Git & GitHub | Version control & collaboration |
	
## 📜 How to Run the Project
### 🔹 Clone the Repository
```sh
git clone https://github.com/your-username/OS-Kernel-Simulator.git
cd OS-Kernel-Simulator
```
### 🔹 Compile the Code
```sh
g++ main.cpp -o kernel_simulator
```
### 🔹 Run the Simulator
```sh
./kernel_simulator
```

## 📂 Project Structure
```plaintext
📁 OS-Kernel-Simulator
 ┣ 📂 src                   # Source code files
 ┣ 📂 include               # Header files
 ┣ 📂 docs                  # Documentation
 ┣ 📄 README.md             # Project documentation
 ┣ 📄 .gitignore            # Git ignore file
 ┣ 📄 LICENSE               # License file
 ┣ 📄 Makefile              # Build automation
 ┗ 📄 os_kernel_simulator   # Compiled output
```
## 📈 Future Enhancements
-🔹 Add Priority Scheduling & Multilevel Queue Scheduling \n
-🔹 Implement Memory Management (Paging, Segmentation) \n
-🔹 Develop a Graphical User Interface (GUI) \n

## 🤝 Contributing
🔹 Contributions are welcome! Follow these steps: \n
1. Fork the [repository](https://github.com/rkbalolkhan/os-kernel-simulator) \n
2. Create a new branch (`feature-xyz`) \n
3. Commit your changes (`git commit -m "Added new feature"`) \n
4. Push to your branch (`git push origin feature-xyz`) \n
5. Create a Pull Request \n

📩 Feel free to open issues and suggest improvements! \n

## 📄 License
🔖 This project is open-source under the MIT License.
