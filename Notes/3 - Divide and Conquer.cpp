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



int main () {
    cout << getCoreNumber() << endl; // 8
    return 0;
}