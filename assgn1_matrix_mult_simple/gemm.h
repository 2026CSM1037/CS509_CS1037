#include <bits/stdc++.h>
using namespace std;
#ifndef GEMM_H
#define GEMM_H

vector<vector<int>> simpleGEMM(vector<vector<int>> &A, vector<vector<int>> &B);

vector<vector<int>> blockingGEMM(vector<vector<int>> &A, vector<vector<int>> &B, int blockSize);

#endif