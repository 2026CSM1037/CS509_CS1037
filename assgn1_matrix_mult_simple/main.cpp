#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "gemm.h"

using namespace std;

int main(){
    ifstream fin("gemm_test_01.txt");

    if(!fin){
        cout << "File not found\n";
        return 0;
    }

    int M, K, N;

    fin >> M >> K >> N;

    vector<vector<int>> A(M, vector<int>(K));
    vector<vector<int>> B(K, vector<int>(N));

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < K; j++)
        {
            fin >> A[i][j];
        }
    }

    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < N; j++)
        {
            fin >> B[i][j];
        }
    }

    fin.close();

    auto start = chrono::high_resolution_clock::now();
    
    vector<vector<int>> C = simpleGEMM(A, B);

    auto end = chrono::high_resolution_clock::now();

    auto time = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Algorithm: GEMM Simple\n";
    cout << "Result Matrix:\n";

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Execution Time: " << time.count() << " milliseconds\n";

    return 0;
}