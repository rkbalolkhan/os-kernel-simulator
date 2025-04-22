# 🖥️ OS Kernel Simulator
## 📌 Project Overview
The OS Kernel Simulator is a C++-based project that simulates essential operating system functionalities, including: <br>
⋅⋅* 🟢 Process Management – Handles process creation, execution, and state transitions. <br>
⋅⋅* 🔵 CPU Scheduling – Implements multiple scheduling algorithms. <br>
⋅⋅* 🔴 Performance Analysis – Displays process execution order, waiting time, and turnaround time. <br>

## 🚀 Features
### 🛠️ Process Management
- ✔️ Uses Process Control Block (PCB) to store process details. <br>
- ✔️ Simulates state transitions: <br>
        `NEW → READY → RUNNING → TERMINATED` <br>

### 🎯 CPU Scheduling Algorithms
- ✔️ First Come First Serve (FCFS) <br>
- ✔️ Shortest Job First (SJF) <br>
- ✔️ Round Robin (RR) <br>

### 📊 Execution & Statistics
- ✔️ Simulates real-time execution using sleep(). <br>
- ✔️ Displays waiting time, turnaround time, and CPU utilization. <br>

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
-🔹 Add Priority Scheduling & Multilevel Queue Scheduling <br>
-🔹 Implement Memory Management (Paging, Segmentation) <br>
-🔹 Develop a Graphical User Interface (GUI) <br>

## 🤝 Contributing
🔹 Contributions are welcome! Follow these steps: <br>
1. Fork the [repository](https://github.com/rkbalolkhan/os-kernel-simulator) <br>
2. Create a new branch (`feature-xyz`) <br>
3. Commit your changes (`git commit -m "Added new feature"`) <br>
4. Push to your branch (`git push origin feature-xyz`) <br>
5. Create a Pull Request <br>

📩 Feel free to open issues and suggest improvements! <br>

## 📄 License
🔖 This project is open-source under the MIT License.
