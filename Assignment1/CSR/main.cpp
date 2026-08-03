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

    for(auto it=graph.begin();it!=graph.end();it++) {
        int key=it->first;
        offset[key]=pos;

        for(int i=0;i<it->second.size();i++) {
            intermediate[pos]=it->second[i].first;
            property[pos]=it->second[i].second;
            pos++;
        }
    }

    offset[vertices-1]=pos;

    auto blockEnd=chrono::high_resolution_clock::now();
    auto blockTime=chrono::duration_cast<chrono::milliseconds>(blockEnd-blockStart);

    cout<<"Offset Array"<<endl;
    printArray(offset,vertices);

    cout<<"Intermediate Array"<<endl;
    printArray(intermediate,pos);

    cout<<"Property Array"<<endl;
    printArray(property,pos);

    cout<<"CSR conversion completed in : "<<blockTime.count()<<" milliseconds"<<endl;

    return 0;
}