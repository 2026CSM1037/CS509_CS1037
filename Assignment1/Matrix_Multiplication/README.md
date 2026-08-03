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

## Project Structure

```
.
├── main.cpp
├── gemm.h
├── gemm_simple.cpp
├── gemm_blocking.cpp
├── gemm_test_01.txt
├── Makefile
├── README.md
└── generate_custom_test_case
    ├── generate_custom_test_case.cpp
    └── output
        ├── custom_test_case.txt
        └── generate_custom_test_case.exe 
```

## Input Format

The input file should be in the following format:

```
M K N
Matrix A (M x K)
Matrix B (K x N)
```

Example:

```
2 3 2
1 2 3
4 5 6
7 8
9 10
11 12
```

## Generating Custom Test Cases

A helper program is provided to generate custom test cases in the required format.

```
M K N
Matrix A
Matrix B
```

To generate a test case:

1. Run `generate_custom_test_case.exe`.
2. The generated test case will be written to `custom_test_case.txt`.
3. Copy the contents of `custom_test_case.txt` into `gemm_test_01.txt`.
4. Run the matrix multiplication program.

This allows different matrix sizes to be tested without manually creating the input file.

## Compilation

Using Makefile:

```bash
mingw32-make
```

Or compile manually:

```bash
g++ main.cpp gemm_simple.cpp gemm_blocking.cpp -o matrix_mult_exec.exe
```

## Running the Program

```bash
./matrix_mult_exec.exe
```

The program reads the input matrix from `gemm_test_01.txt`.

## Output

The program prints:

- Result matrix for Simple GEMM
- Execution time for Simple GEMM
- Result matrix for Blocking GEMM
- Execution time for Blocking GEMM

## Block Size

The blocking implementation currently uses a block size of **32**.

## Notes

- Execution time includes only the matrix multiplication algorithm.
- File reading and output printing are not included in the measured execution time.
- Both implementations produce the same result matrix.