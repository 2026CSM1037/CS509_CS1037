#include <bits/stdc++.h>

#include "gemm.h"

using namespace std;

void printMatrix(vector<vector<int>> &matrix) {
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printResult(string algorithm, vector<vector<int>> &matrix, long long executionTime) {
    cout<<"Algorithm :: "<<algorithm<<endl;
    cout<<"Result Matrix ::"<<endl;

    printMatrix(matrix);

    cout<<"Execution Time: "<<executionTime<<" milliseconds\n\n";
}

int main(){
    ifstream fin("gemm_test_01.txt");

    if(!fin){
        cout<<"File not found\n";
        return 0;
    }

    int m,k,n;
    fin>>m>>k>>n;

    vector<vector<int>> A(m,vector<int>(k));
    vector<vector<int>> B(k,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            fin>>A[i][j];
        }
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            fin>>B[i][j];
        }
    }

    fin.close();

    auto simpleStart=chrono::high_resolution_clock::now();
    vector<vector<int>> simpleResult = simpleGEMM(A,B);
    auto simpleEnd=chrono::high_resolution_clock::now();

    auto simpleTime=chrono::duration_cast<chrono::milliseconds>(simpleEnd-simpleStart);

    printResult("GEMM Simple Method",simpleResult,simpleTime.count());

    int blockSize=32;

    auto blockStart=chrono::high_resolution_clock::now();
    vector<vector<int>> blockResult = blockingGEMM(A,B,blockSize);
    auto blockEnd=chrono::high_resolution_clock::now();

    auto blockTime=chrono::duration_cast<chrono::milliseconds>(blockEnd-blockStart);

    printResult("GEMM Blocking Method",blockResult,blockTime.count());

    return 0;
}