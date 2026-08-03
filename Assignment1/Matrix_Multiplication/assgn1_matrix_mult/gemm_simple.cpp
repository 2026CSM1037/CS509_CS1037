#include "gemm.h"

using namespace std;

vector<vector<int>> simpleGEMM(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int a_rows = A.size();
    int b_cols = B[0].size();
    int b_rows = B.size();  // this should be same i.e. a_cols = b_rows

    vector<vector<int>>C(a_rows, vector<int>(b_cols, 0));
    for(int i=0; i<a_rows; i++){
        for(int j=0; j<b_cols; j++){
            int loc = 0;
            for(int k=0;k<b_rows;k++){
                loc+= A[i][k]*B[k][j];
            }
            C[i][j] = loc;
        }
    }
    return C;
}