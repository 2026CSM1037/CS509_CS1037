#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    int m = 60;
    int k = 40; //col of matrix A, also the row of matrix B
    int n = 50;

    random_device rd;
    mt19937 gen(rd());

    int low_val = 1;
    int high_val = 10;

    uniform_int_distribution<int> distr(low_val, high_val);

    ofstream outFile("custom_test_case.txt");   

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    outFile<<m<<" "<<k<<" "<<n<<"\n";
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<k; j++) {
            outFile << distr(gen) << " ";
        }
        outFile << '\n';
    }

    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            outFile << distr(gen) << " ";
        }
        outFile << '\n';
    }

    outFile.close();

    return 0;
}