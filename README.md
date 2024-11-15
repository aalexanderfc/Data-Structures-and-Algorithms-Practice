# Data Structures and Algorithms Project

This repository contains an individual project focused on practicing data structures and algorithms in C++. The project consists of multiple parts, each designed to implement different algorithms or data structures for solving specific problems. The goal of this project is to gain a deeper understanding of efficient data handling and manipulation in C++.

## Project Overview

### Part 1: Counting Sensor Data Records

- Use the code provided in [this Gist](https://gist.github.com/aspcodenet/35b137316df262ff744e3a583bb388d0) as a starting point.
- Write a program to count the number of sensor data records for **Altitude** collected on **2012-01-02**.

### Part 2: SpeedInKmh Check

- Based on the code from [this Gist](https://gist.github.com/aspcodenet/35b137316df262ff744e3a583bb388d0).
- Check if there is any **SpeedInKmh** registration with a value greater than **99.9**.
  - If found, print **"Max speed reached"** to the console.
  - Otherwise, print **"No max speed reached"**.

### Part 3: Updating FuelConsumption

- Start with the code from [this Gist](https://gist.github.com/aspcodenet/35b137316df262ff744e3a583bb388d0).
- Update all **FuelConsumption** records by increasing their values by **75%** due to discovered sensor inaccuracies.

### Part 4: Queue - Healthcare Center Simulator (VG Level)

- Create a healthcare center simulator using a **Queue** data structure.
- Implement an infinite loop where you can:
  - **Add a new patient** to the waiting queue. A patient is a class with **Queue Number**, **Name**, and **Arrival Time**.
  - **Call the next patient** from the queue and print the waiting time (e.g., **"This patient waited 28 seconds"**).

### Part 5: ATM with Map (VG Level)

- Create an **ATM** simulator using a **Map** data structure.
- Use **Account Number** as the key and **Balance** as the value.
- Implement a menu allowing users to:
  - **Create an account**.
  - **Log in** to an account.
  - **Withdraw** or **deposit** money.

### Part 6: LRU Cache with Hockey Players (VG Level)

- Create a file with **100,000 random hockey players**. Each **HockeyPlayer** has an **ID**, **Name**, **Jersey Number**, and **Team Name**.
- Create a class **LRUCache<HockeyPlayer>** with a capacity of **10 players**.
- Implement the **GetPlayer(int id)** method:
  - If the player is in the cache, move them to the front and return the player.
  - If not in the cache, read from the file, insert the player at the front, and remove the last player if necessary.

## Requirements

- **Software**:
  - C++ Compiler (e.g., GCC)
  - Text editor or IDE for writing C++ code

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/aalexanderfc/Data-Structures-and-Algorithms-Practice.git
   cd Data-Structures-and-Algorithms-Practice
   ```

2. **Compile the Code**:
   - Use a C++ compiler to compile the different parts of the project:
   ```bash
   g++ part1.cpp -o part1
   ```

3. **Run the Program**:
   - Execute the compiled program:
   ```bash
   ./part1
   ```

## How It Works

- **Data Handling**: The project includes different parts that demonstrate how to efficiently work with data using various algorithms and data structures, such as queues, maps, and LRU caches.
- **Simulation**: The healthcare center and ATM parts of the project simulate real-world scenarios where data structures like queues and maps are critical for functionality.

## Example Code

Here is an example snippet of the C++ code for adding a patient to the healthcare queue:

```cpp
#include <iostream>
#include <queue>
#include <string>

class Patient {
    int queueNumber;
    std::string name;
    time_t arrivalTime;
    // Constructor and other methods
};

void addPatient(std::queue<Patient>& waitingQueue) {
    // Code to add a new patient to the queue
}
```

For detailed code, please refer to the specific `.cpp` files in the repository.

## Limitations

- The project is focused on basic implementation of algorithms and data structures. More robust error handling and optimization may be required for real-world applications.
- **LRU Cache** implementation is limited to **10 players**, which is suitable for demonstration purposes but may not be sufficient for larger-scale systems.


## Author

Developed by Alexander. Feel free to reach out for more information or collaboration opportunities.

