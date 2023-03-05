#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// instead of i and j, we use x and y to reference matrix coordinates.

bool isValidPosition(int x, int y, int numRows, int numColumns) { // function checks whether specified position is valid or not.
    if (x < 0 || y < 0 || x > numRows - 1 || y > numColumns - 1) {
        return 0; 
    } else {
        return 1;
    }
}

void helper_printVectorContents(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
        printf("%d ", vec.at(i));
	}
}

int main() {
    int numRows, numColumns, oneVals; // m, n, k
    scanf("%d %d %d", &numRows, &numColumns, &oneVals);

    int matrixA[numRows][numColumns] {}; // initializes a m*n matrix with 0 values.

    for (int i = 0; i < oneVals; i++) { // read next k lines of input, which assume matrix is one-based
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--; // since matrix is one-based x and y must be decremented
        matrixA[x][y] = 1; 
    } 

    // code to print contents of matrix, zero-based for own purposes.
    /*
    for (int x = 0; x < numRows; x++) {
        for (int y = 0; y < numColumns; y++) {
            printf("Matrix A element at [%d][%d]: %d\n", x, y, matrixA[x][y]); 
        }
    }
    */

    vector<int> goodNeighbourCount; // we will find max() and count(max()) from this

    // iterates through all elements of the matrix
    for (int x = 0; x < numRows; x++) { // loops from 0 to (numRows - 1)
        for (int y = 0; y < numColumns; y++) { // loops from 0 to (numColumns - 1)
            int currentValue = matrixA[x][y];
            int goodNeighbours = 0;
            // considers neighbours individually
            if (isValidPosition(x - 1, y - 1, numRows, numColumns)) { // checks if position of neighbour valid.
                if (currentValue == matrixA[x - 1][y - 1]) { // if valid, check if current value = neighbour value
                    goodNeighbours++;
                }
            }
            if (isValidPosition(x, y - 1, numRows, numColumns)) {
                if (currentValue == matrixA[x][y - 1]) {
                    goodNeighbours++;
                }
            }
            if (isValidPosition(x + 1, y - 1, numRows, numColumns)) {
                if (currentValue == matrixA[x + 1][y - 1]) {
                    goodNeighbours++;
                }
            }
            if (isValidPosition(x - 1, y, numRows, numColumns)) {
                if (currentValue == matrixA[x - 1][y]) {
                    goodNeighbours++;
                }
            }
            if (isValidPosition(x + 1, y, numRows, numColumns)) {
                if (currentValue == matrixA[x + 1][y]) {
                    goodNeighbours++;
                }
            }
            if (isValidPosition(x - 1, y + 1, numRows, numColumns)) {
                if (currentValue == matrixA[x - 1][y + 1]) {
                    goodNeighbours++;
                }
            }
            if (isValidPosition(x, y + 1, numRows, numColumns)) {
                if (currentValue == matrixA[x][y + 1]) {
                    goodNeighbours++;
                }
            }
            if (isValidPosition(x + 1, y + 1, numRows, numColumns)) {
                if (currentValue == matrixA[x + 1][y + 1]) {
                    goodNeighbours++;
                }
            }
            goodNeighbourCount.push_back(goodNeighbours);
        }
    }

    //helper_printVectorContents(goodNeighbourCount);

    // 1. find maximum element from goodNeighbourCount. this is x.
    // 2. find number of times x occurs. this is y.
    // 3. printf x and y.   

    int maxValue = *max_element(goodNeighbourCount.begin(), goodNeighbourCount.end());
    int countOfMax = count(goodNeighbourCount.begin(), goodNeighbourCount.end(), maxValue);
    printf("%d %d", maxValue, countOfMax); 

}