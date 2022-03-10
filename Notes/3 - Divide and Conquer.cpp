// Created on March, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <thread>
using namespace std;

int getCoreNumber() {
    return std::thread::hardware_concurrency();
}

// A <- Array
// p <- left index
// r <- right index

void MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = math.floor((p+q) / 2);
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

// @Overload
void Merge(int A[], int p, int q, int r) {

    // copy -> S(n) = O(n)
    int L[](p, q);      // left
    int R[](q+1, r);    // right

    int i = 1, j = 1;
    for (int k = p ; k < r ; k++) {
        if (L[i] <= R[i]>) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

// @Overload
void Mergesort(int A[], int p, int q, int r, int threads) {
    if (p < r) {
        int q = math.floor((p+q) / 2);
        if (threads > 1) {
            std::thread t ([=]() {          // Lança a função para outro core
                MergeSort(A, p, q, thread / 2);
            });
            MergeSort(A, q+1, r, threads / 2);
            t.join();                       // Espera que a outra thread termine
        } else {
            MergeSort(A, p, q, 1);
            MergeSort(A, q+1, r, 1);
        }
        Merge(A, p, q, r);
    }
}

double power (double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    else {
        double d = power(x, n/2);
        if (n % 2 == 0) return d * d;
        else return x * d * d;
    }
}

int main () {
    cout << getCoreNumber() << endl; // 8
    return 0;
}