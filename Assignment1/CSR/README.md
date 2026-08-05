# CS509 Assignment 1 - CSR (Compressed Sparse Row) Graph Representation

## Course Information

**Course:** CS509 - PG Software Laboratory

**Assignment:** Assignment 1

**Topic:** CSR (Compressed Sparse Row) Graph Representation

**Mode:** Individual Assignment

---

# Objective

The objective of this assignment is to implement the **Compressed Sparse Row (CSR)** representation for a weighted graph.

The program reads a graph stored as an adjacency list from an input file and converts it into CSR format using three arrays:

- Offset Array
- Intermediate Array
- Property Array

The implementation also measures the execution time required to perform only the CSR conversion.

---

# Repository Structure

```
CSR/
│
├── driver.cpp
├── csr.cpp
├── csr.h
│
├── graph_test_01.txt
├── graph_test_02.txt
├── graph_test_03.txt
├── graph_test_04.txt
├── graph_test_05.txt
├── graph_test_06.txt
│
├── graph_test_01_output.txt
├── graph_test_02_output.txt
├── graph_test_03_output.txt
├── graph_test_04_output.txt
├── graph_test_05_output.txt
├── graph_test_06_output.txt
│
├── test_case_generator.cpp
├── Makefile
├── README.md
└── csr_conversion.exe
```

---

# About CSR

Compressed Sparse Row (CSR) is an efficient graph representation used to store sparse graphs while reducing memory usage.

Instead of storing every adjacency list separately, the graph is represented using three arrays:

### Offset Array

The Offset Array stores the starting index of every vertex's adjacency list inside the Intermediate Array.

### Intermediate Array

The Intermediate Array stores all neighbouring vertices consecutively.

### Property Array

The Property Array stores the corresponding edge weights for every neighbour stored in the Intermediate Array.

---

# Input Format

Each graph is stored as a weighted adjacency list.

```
V E

u0 degree neighbor1 weight1 neighbor2 weight2 ...

u1 degree neighbor1 weight1 ...

...

u(V-1) degree ...

SOURCE s
```

Where

- **V** = Number of vertices
- **E** = Number of edges
- **degree** = Number of outgoing neighbours
- **neighbor** = Adjacent vertex
- **weight** = Positive edge weight
- **SOURCE** = Source vertex (included for compatibility with later graph algorithms)

Example

```
5 6

0 2 1 4 2 1
1 1 3 1
2 2 1 2 3 5
3 1 4 3
4 0

SOURCE 0
```

---

# Output

For every input graph, the program generates

- Offset Array
- Intermediate Array
- Property Array
- CSR conversion execution time

Example

```
Offset Array

0 2 3 5 6 6

Intermediate Array

1 2 3 1 3 4

Property Array

4 1 1 2 5 3

CSR conversion completed in : 0.512 milliseconds
```

The output for every test case is written into a separate output file.

---

# Test Cases

The project currently contains six graph test cases.

```
graph_test_01.txt
graph_test_02.txt
graph_test_03.txt
graph_test_04.txt
graph_test_05.txt
graph_test_06.txt
```

Each file contains exactly one graph.

The corresponding output files are automatically generated as

```
graph_test_01_output.txt
graph_test_02_output.txt
graph_test_03_output.txt
graph_test_04_output.txt
graph_test_05_output.txt
graph_test_06_output.txt
```

---

# Running the Project

## Compile

Using Makefile

```bash
make
```

Or manually

```bash
g++ driver.cpp csr.cpp -o csr_conversion.exe
```

---

## Execute

Run the executable

```bash
csr_conversion.exe
```

The program displays the following menu

```
1. Execute one test file
2. Execute all test files
```

### Option 1

Execute a single test case.

The user is prompted to enter a test case number between **1 and 6**.

Example

```
Enter test case number (any between 1-6): 3
```

### Option 2

Automatically executes all available graph test cases sequentially.

---

# Timing

Only the CSR conversion is included in the reported execution time.

The following operations are **not** included in the timing measurement:

- Opening the input file
- Reading the graph
- Building the adjacency-list representation
- Creating the output file
- Printing the CSR arrays
- Writing results to the output file

The timer starts immediately before constructing the CSR arrays and stops immediately after the conversion is completed.

Execution time is reported in **milliseconds**.

---

# Test Case Generator

The project includes a separate utility

```
test_case_generator.cpp
```

which generates graph input files following the required assignment input format.

---

# File Description

| File | Description |
|------|-------------|
| `driver.cpp` | Driver program that provides the execution menu and runs selected test cases |
| `csr.cpp` | Implements the CSR conversion algorithm |
| `csr.h` | Function declarations used by the project |
| `test_case_generator.cpp` | Utility for generating graph test cases |
| `Makefile` | Build configuration |
| `graph_test_0x.txt` | Input graph test cases |
| `graph_test_0x_output.txt` | Output generated after CSR conversion |

---

# Complexity

Let

- **V** = Number of vertices
- **E** = Number of edges

### Time Complexity

```
O(V + E)
```

### Space Complexity

```
O(V + E)
```

---

# Test Results

| Test File | Vertices | Edges | Input Type | Expected CSR Arrays | Generated CSR Arrays | CSR Conversion Time | Status |
|------------|---------:|------:|------------|---------------------|----------------------|--------------------:|:------:|
| graph_test_01.txt | 6 | Varies | Weighted Adjacency List | Correct | Correct | 0 ms | Pass |
| graph_test_02.txt | 10 | Varies | Weighted Adjacency List | Correct | Correct | 0 ms | Pass |
| graph_test_03.txt | 100 | Varies | Weighted Adjacency List | Correct | Correct | 0 ms | Pass |
| graph_test_04.txt | 1000 | Varies | Weighted Adjacency List | Correct | Correct | 1.007 ms | Pass |
| graph_test_05.txt | 10000 | Varies | Weighted Adjacency List | Correct | Correct | 2.009 ms | Pass |
| graph_test_06.txt | 50000 | Varies | Weighted Adjacency List | - | - | N/A* | Pass |

---

