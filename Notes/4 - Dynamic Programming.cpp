#include <iostream>
using namespace std;

long combinations1(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return combinations1(n-1, k) + combinations1(n-1, k-1);
    }
}

long combinations2(int n, int k) {
    static long memory[100][100];       // considerando somente n <= 99
    if (memory[n][k] != 0) {
        return memory[n][k];
    } else {
        long solution;
        if (k == 0 || k == n) {
            solution = 1;
        } else {
            solution = combinations2(n-1, k) + combinations2(n-1, k-1);
        }
        memory[n][k] = solution;
        return solution;
    }
}

long combinations3(int n, int k) {
    int maxj = n - k;
    long c[1 + maxj];
    for (int j = 0; j <= maxj; j++)
        c[j] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= maxj; j++)
            c[j] += c[j-1];
    return c[maxj];
}

int fib1(int n) {
    switch (n) {
        case 0: return 0;
        case 1: return 1;
        default: return fib1(n-1) + fib1(n-2);
    }
}

int fib2(int n) {
    int a=1, b=0;
    for (int i = 1 ; i <= n ; i++) {
        int t = a;
        a = b;
        b += t;
    }
    return b;
}

int main () {

    cout << "First example: nCk combinations" << endl;
    cout << combinations1(5, 2) << endl;
    cout << combinations2(5, 2) << endl;
    cout << combinations3(5, 2) << endl;

    cout << "Third example: fibonacci numbers" << endl;
    cout << fib1(10) << endl;
    cout << fib2(10) << endl;

    return 0;
}