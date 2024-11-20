# Smart Traffic Management System

A **Smart Traffic Management System** implemented in C, designed to optimize traffic flow in urban areas using data structures like linked lists and queues. This project manages vehicles at intersections and dynamically adjusts signal timers to ensure efficiency.

## Features
- **Dynamic Intersection Management**: Add and manage multiple intersections.
- **Vehicle Queue Management**: Enqueue vehicles (Normal/Emergency) at specific intersections.
- **Signal Timer Adjustment**: Dynamically adjusts timers based on queue sizes.
- **Vehicle Processing**: Processes vehicles at intersections based on timers.
- **Queue Visualization**: Displays intersections and their respective vehicle queues.

---

## Getting Started

### Prerequisites
- **C Compiler**: GCC or any compatible C compiler.
- Basic knowledge of linked lists and queues in C.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/username/smart-traffic-management.git
   ```
2. Navigate to the directory:
   ```bash
   cd smart-traffic-management
   ```
3. Compile the code:
   ```bash
   gcc -o traffic_management Main.c
   ```

4. Run the executable:
   ```bash
   ./traffic_management
   ```

---

## Usage
1. Select an operation from the menu:
   - Add intersections by specifying their unique IDs.
   - Add vehicles (Normal/Emergency) to specific intersections.
   - Process vehicles to simulate traffic flow.
   - Adjust signal timers to optimize the intersection clearing process.
   - Display all intersections and their vehicle queues.

2. Exit the program by selecting option `6`.

### Example Workflow
- Add an intersection:
  ```
  Enter Intersection ID: 101
  ```
- Add a vehicle:
  ```
  Enter Intersection ID: 101
  Enter Vehicle ID: 1
  Enter Vehicle Type (Normal/Emergency): Normal
  ```
- Process vehicles:
  ```
  Processing Intersection 101:
  Processing Vehicle 1 (Normal)
  ```

---

## Code Overview

### Core Data Structures
1. **Vehicle**:
   - Attributes: ID, Type (Normal/Emergency).
   - Linked in a queue.

2. **Intersection**:
   - Attributes: ID, Vehicle queue, Signal timer.
   - Linked in a list of intersections.

### Key Functions
- **createVehicle()**: Creates a new vehicle.
- **createIntersection()**: Creates a new intersection.
- **addIntersection()**: Adds intersections dynamically to the linked list.
- **addVehicle()**: Enqueues vehicles at a specified intersection.
- **processVehicles()**: Processes vehicles based on signal timers.
- **adjustSignalTimer()**: Adjusts timers dynamically based on queue sizes.
- **displayIntersections()**: Displays intersection details and vehicle queues.

---

## Contribution
Contributions are welcome! Submit pull requests or raise issues for improvements.

### To-Do
- Add file-based data persistence for traffic history.
- Implement advanced algorithms for signal optimization.
- Extend vehicle types with more properties.

---

## License
This project is licensed under the MIT License. See `LICENSE` for details.

---

Developed by **[Aarav Saroliya](https://github.com/Aarav1611)**.
