#include <bits/stdc++.h>
using namespace std;

vector<int> processVector(int vectorSize) { 
    vector<int> newVec;
    for (int i = 0; i < vectorSize; i++) {
        int currentInt;
        scanf("%d", &currentInt);
        newVec.push_back(currentInt);
    }
    return newVec;
}

int main() {
    int rows, columns; // n = rows, m = columns
    scanf("%d %d", &rows, &columns);
    int initial[rows][columns] {}; // all 0 values
    int desired[rows][columns] {};

    for (int row = 0; row < rows; row++) {
        // first row, take in column values (m)
        vector<int> weights;
        weights = processVector(columns);
        for (int column = 0; column < columns; column++) { // column acts as an index
            initial[row][column] = weights[column];
        }
    }

    // takes in desired matrix
    for (int row = 0; row < rows; row++) {
        // first row, take in column values (m)
        vector<int> weights;
        weights = processVector(columns);
        for (int column = 0; column < columns; column++) { // column acts as an index
            desired[row][column] = weights[column];
        }
    }

    

    

    /*
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            printf("Matrix element at [%d][%d]: %d\n", x, y, initial[x][y]); 
        }
    }

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            printf("Matrix element at [%d][%d]: %d\n", x, y, desired[x][y]); 
        }
    }
    */




}