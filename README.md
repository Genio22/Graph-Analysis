# Random Undirected Graph Generator

## Overview
This project is a **Mini Project 2** for even-numbered groups, implemented in C. The program randomly generates undirected graphs represented by adjacency matrices for different values of **n** (number of vertices). It computes the number of edges, vertex degrees, verifies the Handshaking Lemma, and measures computational time.

## Features
- Generates an **undirected graph** using an **adjacency matrix representation**.
- Computes the **number of edges** and **degree of each vertex**.
- Verifies the **Handshaking theorem** (sum of degrees = 2 × number of edges).
- Measures **computational time** in milliseconds.
- Runs experiments for **n = 1000, 2000, 3000, 4000, and 5000**.
- Provides data for **time complexity analysis** using Excel.

## Project Requirements
- **Programming Language:** C
- **Compiler:** GCC or any standard C compiler
- **Tools for Analysis:** Microsoft Excel (for polynomial trendline and complexity analysis)

## How to Run the Code
1. Clone this repository:
   ```sh
   git clone https://github.com/Genio22/Graph-Analysis.git
   ```
2. Compile the C program:
   ```sh
   gcc graph_generator.c -o graph_generator
   ```
3. Run the executable:
   ```sh
   ./graph_generator
   ```

## Expected Output Format
For each **n**, the program outputs:
```
n = 1000:
  Number of edges = XXXX
  Sum of degrees = XXXX
  Handshaking lemma holds: Yes/No
  Time taken = XX.XX ms
```
This repeats for **n = 2000, 3000, 4000, 5000**.

## Theoretical vs Experimental Complexity
- The program’s expected time complexity is **O(n²)** due to nested loops.
- Experimental results will be analyzed in **Microsoft Excel** using a **polynomial trendline**.
- The **trendline equation** will help determine actual computational complexity.

## Deliverables
1. **C Source Code** (`graph_generator.c`)
2. **3-Page Report** (explaining implementation, results, and complexity comparison)
3. **PowerPoint Presentation** (for final project presentation)

## Contributors
- **Team Scorpion**

## License
This project is publicly available for educational purposes. Feel free to use and modify it.

