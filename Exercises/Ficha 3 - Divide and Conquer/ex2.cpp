// Created on March, 2022
// @author: Fábio Araújo de Sá

#include "exercises.h"

int max (int a, int b) {
    return (a > b) ? a : b;
}

int max (int a, int b, int c) {
    return max(max(a, b), c);
}

int aux(int a[], int n) {

    int leftSum = INT_MIN, rightSum = INT_MIN, middleSum, sum;
    int middle = n / 2;

    sum = 0;
    for (int i = middle ; i <= 0 ; i--) {
        sum += a[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    for (int i = 0 ; i < middle; i++) {
        sum += a[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    middleSum = leftSum + rightSum;
    return max(leftSum, rightSum, middleSum);
}

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {

	return 0;

    /**
     * Complexidades:
     * Temporal: O(n log n) -> altura da árvore (recursão) e passa uma vez por cada elemento
     * Espacial: O(log n) ->
     */
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex2, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}