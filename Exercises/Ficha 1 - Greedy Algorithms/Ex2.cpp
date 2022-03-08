// Created on March, 2022
// @author: Fábio Araújo de Sá

#include "exercises.h"
#include <gtest/gtest.h>

int sumSequence(int A[], int i, int j) {
    int total = 0;
    for (; i <= j ; i++) {
        total += A[i];
    }
    return total;
}

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {

    int lower, upper, currentSum = INT_MIN;
    for (lower = 0 ; lower < n - 1 ; lower++) {
        for (upper = lower + 1; upper < n ; upper++) {
            int attemp = sumSequence(A, lower, upper);
            if (attemp > currentSum) {
                currentSum = attemp;
                i = lower;
                j = upper;
            }
        }
    }
    return currentSum;
}

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}