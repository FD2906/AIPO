#include <bits/stdc++.h>
/*
#include <cstdio>
#include <vector>
*/

using namespace std;

vector<int> processVector(int vectorSize) { // processes the second line's integers and stores them in a vector.
    vector<int> newVec;
    for (int i = 0; i < vectorSize; i++) {
        int currentInt;
        scanf("%d", &currentInt);
        newVec.push_back(currentInt);
    }
    return newVec;
}

int main() {
    int n, x;
    vector<int> operations;
    scanf("%d %d", &n, &x);
    operations = processVector(n);

    int opsPerSec = 1;
    int changeableSum = accumulate(operations.begin(), operations.end(), 0);

    while (changeableSum >= x && changeableSum >= 1) {
        opsPerSec++;
        changeableSum = accumulate(operations.begin(), operations.end(), 0) / opsPerSec;
        if (changeableSum <= x) {
            cout << opsPerSec;
            return 0;
        }
    }
    cout << -1;

}