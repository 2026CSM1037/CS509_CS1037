#include "gemm.h"

using namespace std;

vector<vector<int>> blockingGEMM(vector<vector<int>> &A, vector<vector<int>> &B, int blockSize) {
    int m=A.size();
    int k=A[0].size();
    int n=B[0].size();

    vector<vector<int>> C(m,vector<int>(n,0));

    for(int rowBlock=0; rowBlock<m; rowBlock+=blockSize) {
        for(int colBlock=0; colBlock<n; colBlock+=blockSize) {
            for(int innerBlock=0; innerBlock<k; innerBlock+=blockSize) {

                for(int i=rowBlock; i<min(rowBlock+blockSize,m); i++) {
                    for(int j=colBlock; j<min(colBlock+blockSize,n); j++) {
                        for(int x=innerBlock; x<min(innerBlock+blockSize,k); x++) {

                            C[i][j]+=A[i][x]*B[x][j];
                        
                        }
                    }
                }

            }
        }
    }

    return C;
}