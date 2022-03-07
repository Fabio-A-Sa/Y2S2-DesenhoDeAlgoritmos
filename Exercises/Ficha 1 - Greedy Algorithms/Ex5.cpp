// Created on March, 2022
// @author: Fábio Araújo de Sá

#include "exercises.h"
#include <gtest/gtest.h>

unsigned int sumArray(unsigned int a[], unsigned int n) {
    unsigned int sum = 0;
    for(unsigned int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

bool equal(int nonGreedy[], int greedy[], int n) {
    for (int i = 0 ; i < n ; i++) {
        if (nonGreedy[i] != greedy[i]) return false;
    }
    return true;
}

bool isCanonical(unsigned int C[], unsigned int n) {

    for (int i = C[2]+1 ; i < C[n-1] + C[n-2] ; i++) {
        int usedCoinsBT[n];
        int usedCoinsGreedy[n];
        // chamar as funções
        if (!equal(usedCoinsBT, usedCoinsGreedy, n)) return false;
    }
    return true;
}

TEST(TP1_Ex5, canonicalTrue) {
    unsigned int C[] = {1,2,5};
    EXPECT_EQ(isCanonical(C,3), true);

    unsigned int C2[] = {1,2,5,10};
    EXPECT_EQ(isCanonical(C2,4), true);
}

TEST(TP1_Ex5, canonicalFalse) {
    unsigned int C[] = {1,4,5};
    EXPECT_EQ(isCanonical(C,3), true);
}