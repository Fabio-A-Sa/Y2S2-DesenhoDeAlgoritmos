// Created on March, 2022
// @author: Fábio Araújo de Sá

#include "exercises.h"
#include <iostream>
#include <cmath>
using namespace std;

int sumValues(vector<int> results, int i , int j) {
    int total = 0;
    for (; i <= j ; i++) total += results[i];
    return total;
}

bool isSolution (unsigned int C[], int currentCandidate[], int n, int T) {
    int total = 0;
    for (int i = 0 ; i < n ; i++) {
        total += C[i] * currentCandidate[i];
    }
    return total == T;
}

int sum(int attemp[], int n) {
    int total = 0;
    for (int i = 0 ; i < n ; i++) {
        total += attemp[i];
    }
    return total;
}

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {

    /* Formalização do problema
    Input:              C, ci, i pertence [1, n]
                        St, si, i pertence [1, n]
                        T > 0
    Output:             UsedCoins, ui pertence [1, n]
    Constraints:        (soma i -> (1..n) ci * ui) == T
                        para qualquer i pertence [1, n] ui >= si
    Objective Function: return std::min (soma i -> ui)
    */

    const unsigned int maxCoins = 20;
    int currentCandidate[maxCoins];
    bool foundSolution = false;
    int minCoins = INT_MAX;

    for (int i = 1 ; i < n ; i++) {
        currentCandidate[i] = 0;                            // Preparar o primeiro candidato
    }

    while (true) {
        if (isSolution(C, currentCandidate, n, T)) {        // verificar se currentCandidate é solução
            int attemp = sum(currentCandidate, n);
            if (attemp < minCoins) {                        // se for melhor, troca a solução
                minCoins = attemp;
                for (int i = 0 ; i < n ; i++) {
                    usedCoins[i] = currentCandidate[i];
                }
            }
        } else {                                            // gerar próximo candidato
            return false;
        }
    }
}

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingBF(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int Stock[] = {2,2,1};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}