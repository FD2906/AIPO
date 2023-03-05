#include <cstdio>
#include <algorithm>
#include <vector>

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

void helper_printVectorContents(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
        printf("%d ", vec.at(i));
	}
}

int main() {
    // read the input line by line. first line takes in n and x, second line processes vector
    int numOfChildren; // represents n
    int maxWeightOfGondola; // represents x
    scanf("%d %d", &numOfChildren, &maxWeightOfGondola); 
    vector<int> childrensWeights = processVector(numOfChildren);

    /*
    1. max weight case - a child whose weight = max weight gets a gondola to themselves
    2. pairing - standard case - the child w/ least weight is paired to the child w/ max weight. sum must be <= maxWeightOfGondola
    3(i). exception - if sum </= maxWeightOfGondola, child w/ second highest weight considered.
    3(ii). exception 2 - if no children w/ can pair, the child w/ least weight gets their own gondola.
    4. final child remaining in vector gets their own gondola.
    */

    // step 1 - max weight case
    sort(childrensWeights.begin(), childrensWeights.end()); // sorts vector in place in ascending order
    int gondolaCount = 0;

    // find separate gondolas for all children whose weight = max weight
    int childrenBefore = childrensWeights.size();
    childrensWeights.erase(remove(childrensWeights.begin(), childrensWeights.end(), maxWeightOfGondola), childrensWeights.end()); // removes all occurences of max weight
    // helper_printVectorContents(childrensWeights);
    int childrenAfter = childrensWeights.size();
    gondolaCount += (childrenBefore - childrenAfter); // separate gondolas for all the max weight children.

    // step 2 - pairing, standard case
    while (not childrensWeights.empty()) {
        if (childrensWeights.size() > 1) {

            int firstInt = childrensWeights[0];
            int lastIntIndex = childrensWeights.size() - 1; // will come in handy for 3(i) and removing with .erase()
            int lastInt = childrensWeights[lastIntIndex];

            if ((firstInt + lastInt) <= maxWeightOfGondola) {
                childrensWeights.erase(childrensWeights.begin() + lastIntIndex);
                childrensWeights.erase(childrensWeights.begin());
                gondolaCount++;
            } else {
                // step 3(i) - exception - child w/ second highest weight considered, and this lowers until a child is found where step 2 is satsified.
                for (int i = lastIntIndex - 1; i >= 0; i--) { // reverse loop needed to find a 
                    if (i == 0) {
                        // step 3(ii) - must be considered first - child w/ least weight gets their own gondola
                        childrensWeights.erase(childrensWeights.begin());
                        gondolaCount++;
                        break;
                    } else if ((firstInt + childrensWeights[i]) <= maxWeightOfGondola) {
                        childrensWeights.erase(childrensWeights.begin() + i);
                        childrensWeights.erase(childrensWeights.begin());
                        gondolaCount++;
                        break;
                    }
                }
            }
        } else if (childrensWeights.size() == 1) {
            // step 4 - final child in vector - this wouldn't work if an else block is used (vec.size == 0...)
            gondolaCount++;
            childrensWeights.clear();
        }
    }

    printf("%d", gondolaCount); 
}