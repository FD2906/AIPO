#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n) { // generates a vector of prime factors of n.
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n/2;
    }
    for (int i = 3; i < sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

vector<int> sieve(int n) {
    // return vector
    vector<int> returnArr;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            returnArr.push_back(p);
        }
    }
    return returnArr;
}


void printVectorContents(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << '\n';
	}
}

int main() {
    int k, upperBound; // n = upperBound
    scanf("%d %d", &k, &upperBound);

    vector<int> kSmoothNums;
    kSmoothNums = sieve(k);
    //printVectorContents(kSmoothNums);

    int totalNums = 1; // 1 is included.
    for (int i = 0; i < kSmoothNums.size(); i++) {
        int currentFactor = kSmoothNums[i];
        float exponent = 1;
        float testNum = currentFactor * exponent; // powering
        int currentYield = 0;

        while (testNum < upperBound) {
            currentYield++;
            exponent++;
        }
        totalNums += currentYield;
    }
    
    printf("%d", totalNums);
}