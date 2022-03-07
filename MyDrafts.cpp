// Created on March, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Activity {
    string name;
    int start;
    int finish;
};

template <class T>
void showContent(const vector<T> &content) {
    for (const T &item : content) {
        cout << item << " ";
    } cout << endl;
}

void showContent(const vector<Activity> &activities) {
    for (const Activity &activity : activities) {
        cout << activity.name << " -> " << activity.start << ":" << activity.finish << endl;
    }
}

vector<int> extract(int total, const vector<int> &coins) {

    vector<int> solution = {};
    priority_queue<int> sortedCoins(coins.begin(), coins.end());
    int currentAttemp;

    while (total > 0 && !sortedCoins.empty()) {
        currentAttemp = sortedCoins.top();
        sortedCoins.pop();
        if (total - currentAttemp >= 0) {
            solution.push_back(currentAttemp);
            total -= currentAttemp;
        } else continue;
    }

    if (total != 0) solution.clear();
    return solution;
}

void coins() {
    vector<int> coins = {1, 1, 1, 2, 2, 2, 2, 5, 5, 10};
    int total = 8;
    cout << "Coins: ";
    showContent(extract(total, coins));
}

vector<Activity> getNonOverlappingActivities(const vector<Activity> &content) {

    vector<Activity> activities(content.begin(), content.end());
    sort(activities.begin(), activities.end(), [](const Activity &a1, const Activity &a2) { return a1.finish < a2.finish;} );
    vector<Activity> solution = {};

    solution.push_back(activities.front());
    int currentTime = solution.front().finish;

    for (const Activity &activity : activities) {
        if (currentTime < activity.start) {
            currentTime = activity.finish;
            solution.push_back(activity);
        }
    }
    return solution;
}

void activities() {

    vector<Activity> activities = {{"a1", 1, 3}, {"a2", 4, 6}, {"a3", 0,  7},
                                   {"a4", 2, 9}, {"a5", 5, 11}, {"a6", 8, 12},
                                   {"a7", 1, 13}, {"a8", 10, 14}};

    showContent(getNonOverlappingActivities(activities)); // a1, a2, a6
}

int main () {

    coins();
    activities();
    return 0;
}

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

nt sumSequence(int A[], int i, int j) {
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

