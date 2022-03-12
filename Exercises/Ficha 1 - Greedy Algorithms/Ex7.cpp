// Created on March, 2022
// @author: Fábio Araújo de Sá

#include "exercises.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include <vector>

double minimumAverageCompletionTime(std::vector<unsigned int> tasks, std::vector<unsigned int> &orderedTasks) {

    /* Formalização do problema
     *
     * Input: taskSet = {t1, t2, t3, ..., tn}, n >= 0
     * Output: taskList, para qualquer ti a pertencer a TaskSet, existe pelo menos um j pertencente a [1, n] tal que taskList = i
     * Constraints: para qualquer i pertencente a [i, n]
     * Objective function: std::min (soma(i -> soma(j -> t[tasklist[j]])))
     *
     * Para qualquer i da lista, t(i+1) > t(i), logo a solução ótima é quando a lista está ordenada
     */
    
    sort(tasks.begin(), tasks.end());
    int total = 0;
    int currentTime = 0;
    for (auto task : tasks) {
        orderedTasks.push_back(task);
        currentTime += task;
        total += currentTime;
    }

    return (double) total / tasks.size();
}

TEST(TP1_Ex7, taskOrdering) {
    std::vector<unsigned int> tasks = {15, 8, 3, 10};
    std::vector<unsigned int> orderedTasks;
    double averageTime = minimumAverageCompletionTime(tasks, orderedTasks);
    EXPECT_EQ(orderedTasks.size(), 4 );
    ASSERT_NEAR(averageTime, 17.75, 0.00001);
    ASSERT_THAT(orderedTasks,  ::testing::ElementsAre(3,8,10,15));
}