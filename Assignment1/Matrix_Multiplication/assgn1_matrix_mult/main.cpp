#include <bits/stdc++.h>

#include "gemm.h"

using namespace std;

void printMatrix(vector<vector<int>> &matrix, ofstream &fout) {
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[0].size();j++){
            fout<<matrix[i][j]<<" ";
        }
        fout<<endl;
    }
}

void printResult(string algorithm, vector<vector<int>> &matrix, long long executionTime, ofstream &fout) {
    fout<<"Algorithm :: "<<algorithm<<endl;
    fout<<"Result Matrix ::"<<endl;

    printMatrix(matrix, fout);

    fout<<"Execution Time: "<<executionTime<<" milliseconds\n\n";
    
    cout<<"Algorithm :: "<<algorithm<<endl;
    cout<<"Execution Time: "<<executionTime<<" milliseconds\n\n";
}

void runTest(string fileName) {

    ifstream fin(fileName);
    string outputFile=fileName.substr(0,fileName.find("."))+"_output.txt";
    ofstream fout(outputFile);

    if(!fin){
        cout<<"File not found\n";
        return;
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

    cout<<"\nExecuting "<<fileName<<endl;

    auto simpleStart=chrono::high_resolution_clock::now();
    vector<vector<int>> simpleResult = simpleGEMM(A,B);
    auto simpleEnd=chrono::high_resolution_clock::now();

    auto simpleTime=chrono::duration_cast<chrono::milliseconds>(simpleEnd-simpleStart);

    printResult("GEMM Simple Method",simpleResult,simpleTime.count(), fout);

    int blockSize=32;

    auto blockStart=chrono::high_resolution_clock::now();
    vector<vector<int>> blockResult = blockingGEMM(A,B,blockSize);
    auto blockEnd=chrono::high_resolution_clock::now();

    auto blockTime = chrono::duration<double,milli>(blockEnd-blockStart);

    printResult("GEMM Blocking Method",blockResult,blockTime.count(), fout);
    fout.close();
}

int main(){

    int choice;

    cout<<"1. Execute one test file"<<endl;
    cout<<"2. Execute all test files"<<endl;
    cout<<"Enter choice : ";
    cin>>choice;

    if(choice==1){

        int testNo;
        cout<<"Enter test case number : ";
        cin>>testNo;

        string fileName="gemm_test_0"+to_string(testNo)+".txt";
        runTest(fileName);
    }
    else if(choice==2){

        for(int i=1;i<=5;i++){
            string fileName="gemm_test_0"+to_string(i)+".txt";
            runTest(fileName);
        }
    }
    else{
        cout<<"Invalid Choice"<<endl;
    }

    return 0;
}