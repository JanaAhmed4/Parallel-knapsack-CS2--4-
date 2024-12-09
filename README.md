Parallel and Sequential Implementation of the Knapsack Problem

This repository contains a course project focused on the implementation and performance analysis of the **Knapsack Problem** using both **Sequential** and **Parallel** approaches created by students of Computer Science Group 2, Team 4.

The parallel implementation employs **OpenMP** with different numbers of threads, showcasing the impact of parallelism on execution time.

---

## Contents
- **`01KnapsackCode.cpp`**: Contains the sequential implementation of the knapsack problem.
- **`01knapsackParallel.cpp`**: Contains the parallel implementation using OpenMP with varying numbers of threads.
- **`01knapsackParallelAtomic.cpp`**: Contains the parallel implementation using OpenMP with varying numbers of threads.
- **`01knapsackParallelCritical.cpp`**: Contains the parallel implementation using OpenMP with varying numbers of threads.
- **`01knapsackParallelReduction.cpp`**: Contains the parallel implementation using OpenMP with varying numbers of threads.
- **Execution Time Screenshots**: Includes screenshots of the output for both implementations.
- **Flowchart of sequential Knapsack code1.png & Flowchart of sequential Knapsack code2.png:** Presents a flowcchart of our sequential Knapsack code. 
- **Performance Analysis.png**: Includes comparisons of execution time for sequential vs. different parallel implementations that was done on Intel@i7-1065G7 CPU which is a quad core 201 machine.



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
  
## Additional efforts 
We have created a YouTube video that dives into the benefits of parallelism and its applications in the knapsack problem, explained in an engaging and straightforward way.

Watch the video here: [Parallelized 0/1 Knapsack Problem - Video](https://youtu.be/WFLeM5VRa8c?si=Ul-e55p2FkE96ZKe)
