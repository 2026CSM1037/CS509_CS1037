# CS509 Assignment 1 - GEMM

## Name
Soudip Das

## Roll Number
2026CSM1037

## Description

This assignment implements the following General Matrix Multiplication (GEMM) algorithms:

- Simple Matrix Multiplication
- Blocking Matrix Multiplication

Both implementations read the same input file, compute the matrix multiplication, print the resulting matrix, and report the execution time.

# Repository Structure

```
assgn1_matrix_mult/
│
├── main.cpp
├── gemm.h
├── gemm_simple.cpp
├── gemm_blocking.cpp
│
├── generate_custom_test_case/
│   ├── generate_custom_test_case.cpp
│   └── output/
│
├── gemm_test_01.txt
├── gemm_test_02.txt
├── gemm_test_03.txt
├── gemm_test_04.txt
├── gemm_test_05.txt
│
├── gemm_test_01_output.txt
├── gemm_test_02_output.txt
├── gemm_test_03_output.txt
├── gemm_test_04_output.txt
├── gemm_test_05_output.txt
│
├── Makefile
├── README.md
└── matrix_mult_exec.exe
```

---

# Algorithms Implemented

## 1. Simple GEMM

Computes matrix multiplication using the standard triple nested loop.

Time Complexity:

```
O(M × K × N)
```

Space Complexity:

```
O(M × N)
```

---

## 2. Blocking GEMM

Improves cache locality by dividing the matrices into smaller blocks (tiles).

Advantages

- Better cache utilization
- Reduced cache misses
- Faster for large matrices

Time Complexity

```
O(M × K × N)
```

Space Complexity

```
O(M × N)
```

---

# Input Format

```
M K N

Matrix A

M rows
K columns

Matrix B

K rows
N columns
```

Example

```
2 3 2

1 2 3
4 5 6

7 8
9 10
11 12
```

---

# Output

For every test case, the program produces:

- Result Matrix
- Algorithm Execution Time

The output is written into a separate output file.

Example:

```
Algorithm : Simple GEMM

Result Matrix

58 64
139 154

Execution Time : xx ms
```

---

# Test Cases

The project currently contains five test files.

```
gemm_test_01.txt
gemm_test_02.txt
gemm_test_03.txt
gemm_test_04.txt
gemm_test_05.txt
```

Each file contains one matrix multiplication test case.

---

# Running the Project

Compile

```
make
```

or

```
g++ main.cpp gemm_simple.cpp gemm_blocking.cpp -o matrix_mult_exec
```

---

Execute

Run the executable.

```
./matrix_mult_exec
```

or on Windows

```
matrix_mult_exec.exe
```

The menu provides:

```
1. Execute one test file

2. Execute all test files
```

---

# Timing

Only the execution time of the matrix multiplication algorithm is measured.

The following operations are **not included** in the timing:

- Reading input file
- Parsing matrices
- Memory allocation
- Writing output
- Printing results

This follows the CS509 Assignment Guidelines.

---

# Custom Test Case Generator

A separate utility is provided for generating random GEMM input files.

Location

```
generate_custom_test_case/
```

The generated test cases follow the assignment input format.

---

# Block Size

The blocking implementation uses a configurable block size.

Changing the block size allows experimentation with cache performance.

---

# Files Description

| File | Description |
|------|-------------|
| main.cpp | Driver program |
| gemm_simple.cpp | Standard GEMM implementation |
| gemm_blocking.cpp | Blocking GEMM implementation |
| gemm.h | Common declarations |
| generate_custom_test_case.cpp | Random test case generator |
| Makefile | Build configuration |

---

# Result Table

| Test File | Matrix Dimensions | Expected Output | Actual Output | Simple Time | Blocking Time | Block Size | Status |
|------------|------------------|-----------------|---------------|-------------|---------------|------------|--------|
| gemm_test_01.txt | 60×40, 40×50 | ✔ | ✔ |  0 ms | 0 ms | 32 | Pass |
| gemm_test_02.txt | 10×10, 10×10 | ✔ | ✔ | 0 ms | 0 ms | 32 | Pass |
| gemm_test_03.txt | 100×100, 100×100 | ✔ | ✔ | 0 ms | 0 ms | 32 | Pass |
| gemm_test_04.txt | 500×500, 500×400 | ✔ | ✔ | 50 ms | 44 ms | 32 | Pass |
| gemm_test_05.txt | 1000×1000, 1000×1000 | ✔ | ✔ | 1075 ms | 450 ms | 32 | Pass |

---