#include "exercises.h"

Labyrinth::Labyrinth(int values[10][10]) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            labyrinth[i][j] = values[i][j];
}

#include <iostream>

void  Labyrinth::print() const {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << labyrinth[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Labyrinth::findGoal(int x, int y) {
    solved = false;
    this->initializeVisited();
    find(x, y);
    return solved;
}

void Labyrinth::find(int x, int y) {

    visited[x][y] = true;

    // caso base / paragem
    if (labyrinth[x][y] == 2) {
        solved = true;
    }

    // escolha    
    if (labyrinth[x][y+1] != 0 && !visited[x][y+1]) find(x,y+1); // baixo
    if (labyrinth[x+1][y] != 0 && !visited[x+1][y]) find(x+1,y); // direita
    if (labyrinth[x][y-1] != 0 && !visited[x][y-1]) find(x,y-1); // cima
    if (labyrinth[x-1][y] != 0 && !visited[x-1][y]) find(x-1,y); // esquerda
}

bool Labyrinth::find2(int x, int y) {

    if (visited[x][y] || labyrinth[x][y] == 0) {
        return false;
    }

    visited[x][y] = true;

    if (labyrinth[x][y] == 2) {
        return true;
    }

    return find2(x-1, y) || find2(x+1, y) || find2(x, y-1) || find2(x, y+1);

    /**
     *  Complexidades
     *  Temporal = 0(n^2)
     *  Espacial = O(n^2) -> recursão na stack = número de chamadas
     */
}

void Labyrinth::initializeVisited() {
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            visited[i][j] = false;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex1, testLabyrinthPossible) {
    // This test assumes that the mazes only have a possible path to the exit
    int lab1[10][10] ={
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,0,1,0,0},
        {0,1,0,0,0,1,0,1,0,0},
        {0,1,1,0,1,1,1,1,1,0},
        {0,1,0,0,0,1,0,0,0,0},
        {0,1,0,1,0,1,1,1,1,0},
        {0,1,1,1,0,0,1,0,1,0},
        {0,1,0,0,0,0,1,0,1,0},
        {0,1,1,1,0,0,1,2,0,0},
        {0,0,0,0,0,0,0,0,0,0}};

    Labyrinth l1(lab1);
    EXPECT_EQ(l1.findGoal(1,1),true);
}

TEST(TP2_Ex1, testLabyrinthImpossible) {
    int lab1[10][10] ={
            {0,0,0,0,0,0,0,0,0,0},
            {0,1,1,1,1,1,0,1,0,0},
            {0,1,0,0,0,1,0,1,0,0},
            {0,1,1,0,1,1,1,1,1,0},
            {0,1,0,0,0,1,0,0,0,0},
            {0,1,0,1,0,1,1,1,1,0},
            {0,1,1,1,0,0,1,0,1,0},
            {0,1,0,0,0,0,1,0,1,0},
            {0,1,1,1,0,0,0,2,0,0},
            {0,0,0,0,0,0,0,0,0,0}};

    Labyrinth l1(lab1);
    EXPECT_EQ(l1.findGoal(1,1),false);
}