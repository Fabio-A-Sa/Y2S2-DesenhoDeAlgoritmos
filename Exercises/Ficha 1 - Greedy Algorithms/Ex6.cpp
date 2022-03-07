// Created on March, 2022
// @author: Fábio Araújo de Sá

#include "exercises.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::operator<(const Activity &a2) const {
    return finish < a2.finish;
}

std::vector<Activity> earliestFinishScheduling(std::vector<Activity> A) {

    sort(A.begin(), A.end());
    std::vector<Activity> res = {};
    res.push_back(A[0]);
    int currentTime = A[0].finish;
    for (auto act : A) {
        if (currentTime < act.start) {
            currentTime = act.finish;
            res.push_back(act);
        }
    }
    return res;
}

TEST(TP1_Ex6, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = earliestFinishScheduling(A);
    EXPECT_EQ(V.size(), 3 );
    ASSERT_THAT(earliestFinishScheduling(A),  ::testing::ElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}