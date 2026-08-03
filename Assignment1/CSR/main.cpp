#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100000

void printArray(int arr[], int sz) {
    for(int i=0;i<sz;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {

    ifstream fin("graph_test_01.txt");

    if(!fin) {
        cout<<"File not found\n";
        return 0;
    }

    int vertices, edges;
    fin>>vertices>>edges;

    map<int, vector<pair<int,int>>> graph;

    for(int i=0;i<vertices;i++) {
        int vertex,outDegree;
        fin>>vertex>>outDegree;

        for(int j=0;j<outDegree;j++) {
            int neighbor,weight;
            fin>>neighbor>>weight;

            graph[vertex].push_back({neighbor,weight});
        }
    }

    int offset[MAX_SIZE];
    int intermediate[MAX_SIZE];
    int property[MAX_SIZE];

    fill(offset,offset+MAX_SIZE,-1);
    fill(intermediate,intermediate+MAX_SIZE,0);
    fill(property,property+MAX_SIZE,0);

    int pos=0;

    auto blockStart=chrono::high_resolution_clock::now();

    for(int i=0;i<vertices;i++){
        offset[i] = pos;
        for(int j=0;j<graph[i].size();j++){
            intermediate[pos] = graph[i][j].first;
            property[pos] = graph[i][j].second;
            pos++;
        }
    }

    offset[vertices]=pos; // last index is basically going to store total edges
    // for a vertex with no outgoing edges offset[] is going to be -1

    auto blockEnd=chrono::high_resolution_clock::now();
    auto blockTime=chrono::duration_cast<chrono::milliseconds>(blockEnd-blockStart);

    cout<<"Offset Array"<<endl;
    printArray(offset,vertices+1);

    cout<<"Intermediate Array"<<endl;
    printArray(intermediate,pos);

    cout<<"Property Array"<<endl;
    printArray(property,pos);

    cout<<"CSR conversion completed in : "<<blockTime.count()<<" milliseconds"<<endl;

    return 0;
}