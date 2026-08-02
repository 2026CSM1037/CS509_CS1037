#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    int n = 100;
    int m = 100;

    random_device rd;
    mt19937 gen(rd());

    int low_val = 1;
    int high_val = 10;

    uniform_int_distribution<int> distr(low_val, high_val);

    ofstream outFile("custom_matrix.txt");   

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            outFile << distr(gen) << " ";
        }
        outFile << '\n';
    }

    outFile.close();

    return 0;
}