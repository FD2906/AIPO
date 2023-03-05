#include <cstdio>
using namespace std;

// helper function
bool isPrime(int n) { // naive approach w/ O(n) complexity
    if (n <= 1 || n == 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % 1 == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else {
        int remainder = a % b;
        return gcd(b, remainder); // gcd() has a complexity of O(log(min(a, b)))
    }
}

int main() {
    int c, n;
    scanf("%d %d", &c, &n);
    
    int count = 0;

    // int incrementer = 2 // we consider even nums if c is odd, and odd nums if c is even.
    // v2: we should be adding on c each time, instead of considering only odd/even sums, which makes the search space even smaller.

    for (int a = c; a <= n; a += c) {
        for (int b = c; b <= a; b += c) { // (1) time complexity of O(n^2) and  1 <= a <= b <= n - try to improve this. 
            // (2) n >= c and n >= 1, so c >= 1, so we use c instead of 1. this'll mean less work done.

            /*
            1. check if a = b, if so, return a.
            2. check if a is prime or b is prime, but NOT a = b. if so, return 1.
            3. do normal euclidean algorithm, but make a = 0 and b = 0 take priority, as they are essential to euclidean algorithm/
            */
            
            //printf("Considering a = %d and b = %d ... ", a, b); // test code, comment when presenting solution

            int greatestCommonDivisor;

            if (a == b) {
                greatestCommonDivisor = a;
            } else if ((isPrime(a) || isPrime(b)) && (a != b)) {
                greatestCommonDivisor = 1;
            } else {
                greatestCommonDivisor = gcd(a, b);
            }

            //printf("GCD(%d, %d) = %d.\n", a, b, greatestCommonDivisor); // test code, delete later

            if (c == greatestCommonDivisor) {

                //printf("GCD(%d, %d) = %d matches c = %d!\n", a, b, greatestCommonDivisor, c); // test code, delete later

                count++;

                //printf("Current count: %d\n", count); // test code, delete later
            }
        }
    }
    printf("%d", count % 1000000007); 

}