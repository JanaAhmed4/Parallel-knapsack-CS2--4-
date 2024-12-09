Parallel and Sequential Implementation of the Knapsack Problem

This repository contains a course project focused on the implementation and performance analysis of the **Knapsack Problem** using both **Sequential** and **Parallel** approaches. 
The parallel implementation employs **OpenMP** with different numbers of threads, showcasing the impact of parallelism on execution time.

---

## Contents
- **`sequential_knapsack.cpp`**: Contains the sequential implementation of the knapsack problem.
- **`parallel_knapsack.cpp`**: Contains the parallel implementation using OpenMP with varying numbers of threads.
- **Execution Time Screenshots**: Includes screenshots of the output for both implementations.

---

## Features
1. **Sequential Implementation**:
   - Traditional dynamic programming approach for solving the knapsack problem.
   - No parallelism involved.

2. **Parallel Implementation**:
   - Utilizes OpenMP to parallelize the nested loop in the dynamic programming approach.
   - Supports different numbers of threads (e.g., 1, 2, 4, 6, and 8) to analyze performance scaling.

3. **Performance Analysis**:
   - Includes comparisons of execution time for sequential vs. parallel implementations that was done on Intel@i7-1065G7 CPU which is a quad core 201
machine.
   - Demonstrates speedup with increasing threads.

