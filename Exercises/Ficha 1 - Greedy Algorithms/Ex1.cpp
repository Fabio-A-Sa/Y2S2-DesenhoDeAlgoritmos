// Created on March, 2022
// @author: Fábio Araújo de Sá

#include <gtest/gtest.h>
#include "exercises.h"

bool sum3(unsigned int T, unsigned int nums[3]) {

    for (int i = 0 ; i < T ; i++) {
        for (int j = 0 ; j < T ; j++) {
            for (int k = 0 ; k < T ; k++) {
                if (T == (i+j+k)) {
                    nums[0] = i;
                    nums[1] = j;
                    nums[2] = k;
                    return true;
                }
            }
        }
    }
    return false;
}

bool sum3_a(unsigned int T, unsigned int nums[3]) {

    for (int i = 0 ; i < T ; i++) {
        for (int j = i ; j < T ; j++) {
            for (int k = j ; k < T ; k++) {
                if (T == (i+j+k)) {
                    nums[0] = i;
                    nums[1] = j;
                    nums[2] = k;
                    return true;
                }
            }
        }
    }
    return false;
}

void compareSums(unsigned int selected[3], unsigned int expectedSum) {
    EXPECT_EQ(selected[0] + selected[1] + selected[2], expectedSum);
}

TEST(TP1_Ex1, 3sumExists) {
    unsigned int selected[3];

    unsigned int T = 10;
    EXPECT_EQ(sum3(T,selected), true);
    compareSums(selected,T);

    T = 18;
    EXPECT_EQ(sum3(T,selected), true);
    compareSums(selected,T);
}

TEST(TP1_Ex1, 3sumNotExists) {
    unsigned int selected[3];

    unsigned int T = 1;
    EXPECT_EQ(sum3(T,selected), false);
}