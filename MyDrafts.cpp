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

int sumValues(vector<int> results, int i , int j) {
    int total = 0;
    for (; i <= j ; i++) total += results[i];
    return total;
}

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {

    for (int i = 0 ; i < n ; i++) usedCoins[i] = 0;

    for (int i = n - 1 ; i >= 0 && T > 0; i--) {
        if (Stock[i] > 0 && C[i] <= T) {
            int nMoedas = std::min(Stock[i], T / C[i]);
            usedCoins[i] += nMoedas;
            T -= nMoedas * C[i];
        }
    }

    return T == 0;
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

bool changeMakingGreedy(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {

    for (int i = 0 ; i < n ; i++) usedCoins[i] = 0;

    for (int i = n - 1 ; i >= 0 && T > 0; i--) {
        if (Stock[i] > 0 && C[i] <= T) {
            int nMoedas = std::min(Stock[i], T / C[i]);
            usedCoins[i] += nMoedas;
            T -= nMoedas * C[i];
        }
    }

    return T == 0;
}

TEST(TP1_Ex4, hasGreedyChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingGreedy(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingGreedy(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex4, hasNoGreedyChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingGreedy(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingGreedy(C,Stock,n,1,usedCoins), false);
}

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

double minimumAverageCompletionTime(std::vector<unsigned int> tasks, std::vector<unsigned int> &orderedTasks) {

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

// @ global
vector<int> W = {2, 4, 6};          // vector de dados
vector<bool> sel(8, true);          // sel.size() == math.pow(2, W.size())
int S = 10;                         // soma procurada
int n = 3;                          // número de itens do vector

//Inputs: int W[], int n, int S
//Oututs: bool sel[] - sel[i]=true means W[i] selected (initially false)
//Call initially: sumOfSubsets(0, 0)

bool sumOfSubsets(int i, int sumSel) {

    // if solution found, print and terminate
    if (sumSel == S) { 
        cout << "Solução encontrada!" << endl; 
        return true;
    }

    // if there is no child to explore, just backtrack
    if (i == n) return false;

    // explore item W[i] (try using and not using) (choice point)
    sel[i] = true;
    if (sumOfSubsets(i+1, sumSel + W[i])) return true;  // left
    sel[i] = false;
    if (sumOfSubsets(i+1, sumSel)) return true;         // right

    // no solution found
    return false;
}

int main() {
    sumOfSubsets(0, 0);
    return 0;
}

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

// @Overload
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

// @Overload
void Mergesort(int A[], int p, int q, int r, int threads) {
    if (p < r) {
        int q = math.floor((p+q) / 2);
        if (threads > 1) {
            std::thread t ([=]() {          // Lança a função para outro core
                MergeSort(A, p, q, thread / 2);
            });
            MergeSort(A, q+1, r, threads / 2);
            t.join();                       // Espera que a outra thread termine
        } else {
            MergeSort(A, p, q, 1);
            MergeSort(A, q+1, r, 1);
        }
        Merge(A, p, q, r);
    }
}

int main () {
    cout << getCoreNumber() << endl; // 8
    return 0;
}

double power (double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    else {
        double d = power(x, n/2);
        if (n % 2 == 0) return d * d;
        else return x * d * d;
    }
}

#include <iostream>
using namespace std;

long combinations1(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return combinations1(n-1, k) + combinations1(n-1, k-1);
    }
}

long combinations2(int n, int k) {
    static long memory[100][100];       // considerando somente n <= 99
    if (memory[n][k] != 0) {
        return memory[n][k];
    } else {
        long solution;
        if (k == 0 || k == n) {
            solution = 1;
        } else {
            solution = combinations2(n-1, k) + combinations2(n-1, k-1);
        }
        memory[n][k] = solution;
        return solution;
    }
}

long combinations3(int n, int k) {
    int maxj = n - k;
    long c[1 + maxj];
    for (int j = 0; j <= maxj; j++)
        c[j] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= maxj; j++)
            c[j] += c[j-1];
    return c[maxj];
}

int fib1(int n) {
    switch (n) {
        case 0: return 0;
        case 1: return 1;
        default: return fib1(n-1) + fib1(n-2);
    }
}

int fib2(int n) {
    int a=1, b=0;
    for (int i = 1 ; i <= n ; i++) {
        int t = a;
        a = b;
        b += t;
    }
    return b;
}

int main () {

    cout << "First example: nCk combinations" << endl;
    cout << combinations1(5, 2) << endl;
    cout << combinations2(5, 2) << endl;
    cout << combinations3(5, 2) << endl;

    cout << "Third example: fibonacci numbers" << endl;
    cout << fib1(10) << endl;
    cout << fib2(10) << endl;

    return 0;
}

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

#include <gtest/gtest.h>

TEST(TP2_Ex1, testLabyrinthPossible) {

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

#include "../../../Downloads/TP2a-2/exercises.h"

Sudoku::Sudoku() {
    this->initialize();
}

Sudoku::Sudoku(int nums[9][9]): Sudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (nums[i][j] != 0) {
                int n = nums[i][j];
                if (n < 1 || n > 9 || !accepts(i, j, n))
                    throw IllegalArgumentException;
                else
                    place(i, j, n);
            }
        }
    }
}

void Sudoku::initialize() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int n = 0; n < 10; n++) {
                numbers[i][j] = 0;
                lineHasNumber[i][n] = false;
                columnHasNumber[j][n] = false;
                block3x3HasNumber[i / 3][j / 3][n] = false;
            }
        }
    }
    this->countFilled = 0;
}

bool Sudoku::isComplete() const {
    return countFilled == 9 * 9;
}

bool Sudoku::solve() {
    //TODO
    return false;
}

int Sudoku::countSolutions() {
    //TODO
    return 0;
}

void Sudoku::generate() {
    //TODO
}

int** Sudoku::getNumbers() {
    int** ret = new int*[9];
    for (int i = 0; i < 9; i++) {
        ret[i] = new int[9];
        for (int a = 0; a < 9; a++)
            ret[i][a] = numbers[i][a];
    }
    return ret;
}

#include <iostream>

void Sudoku::print() const {
    for (int i = 0; i < 9; i++) {
        for (int a = 0; a < 9; a++)
            std::cout << this->numbers[i][a] << " ";
        std::cout << std::endl;
    }
}

bool Sudoku::accepts(int i, int j, int n) {
    //TODO
    return false;
}

void Sudoku::place(int i, int j, int n) {
    if (numbers[i][j] != 0)
        return;

    numbers[i][j] = n;
    lineHasNumber[i][n] = true;
    columnHasNumber[j][n] = true;
    block3x3HasNumber[i / 3][j / 3][n] = true;
    countFilled++;
}

int Sudoku::clear(int i, int j) {
    int n = numbers[i][j];

    numbers[i][j] = 0;
    lineHasNumber[i][n] = false;
    columnHasNumber[j][n] = false;
    block3x3HasNumber[i / 3][j / 3][n] = false;
    countFilled--;

    return n;
}

void Sudoku::clear() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (numbers[i][j] != 0)
                clear(i, j);
}

#include <gtest/gtest.h>

void compareSudokus(int in[9][9], int out[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int a = 0; a < 9; a++)
            ASSERT_EQ(in[i][a], out[i][a]);
    }
}

TEST(TP2_Ex2, testSudokuAlreadySolved) {
int in[9][9] =
        {{8, 6, 2, 3, 4, 1, 7, 9, 5},
         {1, 5, 4, 9, 7, 6, 3, 8, 2},
         {9, 3, 7, 8, 2, 5, 1, 4, 6},
         {5, 7, 6, 1, 3, 8, 9, 2, 4},
         {2, 1, 8, 5, 9, 4, 6, 3, 7},
         {3, 4, 9, 7, 6, 2, 8, 5, 1},
         {6, 2, 3, 4, 8, 7, 5, 1, 9},
         {7, 8, 5, 2, 1, 9, 4, 6, 3},
         {4, 9, 1, 6, 5, 3, 2, 7, 8}};

Sudoku s(in);
EXPECT_EQ(s.solve(), true);

int out[9][9];
int** res = s.getNumbers();

for (int i = 0; i < 9; i++)
for (int a = 0; a < 9; a++)
out[i][a] = res[i][a];

compareSudokus(in, out);
}

TEST(TP2_Ex2, testSudokuNoneBackStepsRequired) {
int in[9][9] =
        {{8, 6, 0, 0, 0, 0, 0, 9, 0},
         {0, 0, 4, 0, 7, 6, 3, 0, 0},
         {9, 0, 0, 0, 2, 5, 1, 0, 0},
         {0, 7, 6, 1, 3, 0, 0, 2, 0},
         {2, 1, 0, 0, 0, 0, 0, 3, 7},
         {0, 4, 0, 0, 6, 2, 8, 5, 0},
         {0, 0, 3, 4, 8, 0, 0, 0, 9},
         {0, 0, 5, 2, 1, 0, 4, 0, 0},
         {0, 9, 0, 0, 0, 0, 0, 7, 8}};

int out[9][9] =
        {{8, 6, 2, 3, 4, 1, 7, 9, 5},
         {1, 5, 4, 9, 7, 6, 3, 8, 2},
         {9, 3, 7, 8, 2, 5, 1, 4, 6},
         {5, 7, 6, 1, 3, 8, 9, 2, 4},
         {2, 1, 8, 5, 9, 4, 6, 3, 7},
         {3, 4, 9, 7, 6, 2, 8, 5, 1},
         {6, 2, 3, 4, 8, 7, 5, 1, 9},
         {7, 8, 5, 2, 1, 9, 4, 6, 3},
         {4, 9, 1, 6, 5, 3, 2, 7, 8}};

Sudoku s(in);
EXPECT_EQ(s.solve(), true);

int sout[9][9];
int** res = s.getNumbers();

for (int i = 0; i < 9; i++)
for (int a = 0; a < 9; a++)
sout[i][a] = res[i][a];

compareSudokus(out, sout);
}

TEST(TP2_Ex2, testSudokuSomeBackStepsRequired) {
int in[9][9] =
        {{7, 0, 5, 2, 6, 3, 4, 0, 9},
         {0, 0, 0, 0, 0, 0, 0, 3, 0},
         {0, 0, 0, 0, 8, 0, 0, 0, 0},
         {0, 0, 9, 5, 0, 4, 0, 0, 2},
         {5, 0, 6, 0, 0, 0, 7, 0, 8},
         {2, 0, 0, 8, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 1, 0, 0, 0, 0},
         {0, 2, 0, 0, 0, 0, 0, 0, 0},
         {3, 0, 8, 7, 2, 9, 6, 0, 4}};

int out[9][9] =
        {{7, 1, 5, 2, 6, 3, 4, 8, 9},
         {8, 6, 4, 9, 5, 7, 2, 3, 1},
         {9, 3, 2, 4, 8, 1, 5, 7, 6},
         {1, 8, 9, 5, 7, 4, 3, 6, 2},
         {5, 4, 6, 1, 3, 2, 7, 9, 8},
         {2, 7, 3, 8, 9, 6, 1, 4, 5},
         {4, 9, 7, 6, 1, 5, 8, 2, 3},
         {6, 2, 1, 3, 4, 8, 9, 5, 7},
         {3, 5, 8, 7, 2, 9, 6, 1, 4}};

Sudoku s(in);
EXPECT_EQ(s.solve(), true);

int sout[9][9];
int** res = s.getNumbers();

for (int i = 0; i < 9; i++)
for (int a = 0; a < 9; a++)
sout[i][a] = res[i][a];

compareSudokus(out, sout);
}

TEST(TP2_Ex2, testSudokuManyBackStepsRequired) {
int in[9][9] =
        {{1, 0, 0, 0, 0, 7, 0, 0, 0},
         {0, 7, 0, 0, 6, 0, 8, 0, 0},
         {2, 0, 0, 0, 4, 0, 6, 0, 0},
         {7, 6, 4, 0, 0, 0, 9, 0, 0},
         {0, 0, 0, 0, 2, 0, 5, 6, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 3, 0, 0, 0, 0},
         {4, 0, 0, 1, 0, 0, 0, 0, 5},
         {0, 5, 0, 0, 0, 4, 0, 9, 0}};

int out[9][9] =
        {{1, 4, 6, 8, 5, 7, 2, 3, 9},
         {3, 7, 9, 2, 6, 1, 8, 5, 4},
         {2, 8, 5, 9, 4, 3, 6, 7, 1},
         {7, 6, 4, 3, 1, 5, 9, 2, 8},
         {8, 3, 1, 4, 2, 9, 5, 6, 7},
         {5, 9, 2, 6, 7, 8, 4, 1, 3},
         {9, 1, 8, 5, 3, 2, 7, 4, 6},
         {4, 2, 7, 1, 9, 6, 3, 8, 5},
         {6, 5, 3, 7, 8, 4, 1, 9, 2}};

Sudoku s(in);
EXPECT_EQ(s.solve(), true);

int sout[9][9];
int **res = s.getNumbers();

for (int i = 0; i < 9; i++)
for (int a = 0; a < 9; a++)
sout[i][a] = res[i][a];

compareSudokus(out, sout);
}

TEST(TP2_Ex2, testSudokuWithMinimalClues) {
int in[9][9] =
        {{7, 0, 0, 1, 0, 8, 0, 0, 0},
         {0, 9, 0, 0, 0, 0, 0, 3, 2},
         {0, 0, 0, 0, 0, 5, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 1, 0, 0},
         {9, 6, 0, 0, 2, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 8, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 5, 0, 0, 1, 0, 0, 0},
         {3, 2, 0, 0, 0, 0, 0, 0, 6}};

int out[9][9] =
        {{7, 5, 2, 1, 3, 8, 6, 9, 4},
         {1, 9, 8, 7, 4, 6, 5, 3, 2},
         {4, 3, 6, 2, 9, 5, 7, 8, 1},
         {2, 8, 3, 4, 5, 9, 1, 6, 7},
         {9, 6, 1, 8, 2, 7, 3, 4, 5},
         {5, 7, 4, 6, 1, 3, 8, 2, 9},
         {6, 1, 9, 3, 7, 2, 4, 5, 8},
         {8, 4, 5, 9, 6, 1, 2, 7, 3},
         {3, 2, 7, 5, 8, 4, 9, 1, 6}};

Sudoku s(in);
EXPECT_EQ(s.solve(), true);

int sout[9][9];
int** res = s.getNumbers();

for (int i = 0; i < 9; i++)
for (int a = 0; a < 9; a++)
sout[i][a] = res[i][a];

compareSudokus(out, sout);
}

TEST(TP2_Ex2, testSudokuWithMultipleSolutions) {
int in[9][9] =
        {{0/*7*/, 0, 0, 1, 0, 8, 0, 0, 0},
         {0, 9, 0, 0, 0, 0, 0, 3, 2},
         {0, 0, 0, 0, 0, 5, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 1, 0, 0},
         {9, 6, 0, 0, 2, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 8, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 5, 0, 0, 1, 0, 0, 0},
         {3, 2, 0, 0, 0, 0, 0, 0, 6}};

Sudoku s(in);
EXPECT_EQ(s.solve() && s.isComplete(), true);
int** out = s.getNumbers();
for (int i=0; i<9; i++)
for (int j=0; j<9; j++)
if (in[i][j] != 0)
EXPECT_EQ(in[i][j], out[i][j]);
}

TEST(TP2_Ex2, testSudokuEmpty) {
int in[9][9] =
        {{0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0}};

Sudoku s(in);
EXPECT_EQ(s.solve(), true);
EXPECT_EQ(s.isComplete(), true);
}

TEST(TP2_Ex2, testSudokuImpossible) {
int in[9][9] =
        {{7, 0, 0, 1, 0, 8, 0, 0, 0},
         {4/*0*/, 9, 0, 0, 0, 0, 0, 3, 2},
         {0, 0, 0, 0, 0, 5, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 1, 0, 0},
         {9, 6, 0, 0, 2, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 8, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 5, 0, 0, 1, 0, 0, 0},
         {3, 2, 0, 0, 0, 0, 0, 0, 6}};

Sudoku s(in);
EXPECT_EQ(s.solve(), false);

int out[9][9];
int** res = s.getNumbers();

for (int i = 0; i < 9; i++)
for (int a = 0; a < 9; a++)
out[i][a] = res[i][a];

compareSudokus(in, out);

#include "exercises.h"

bool changeMakingBacktracking(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    //TODO
    return false;

    /*  Complexidades:
     *  S -> stock máximo
     *  D -> diferentes moedas (tamanho do array solução)
     *  Temporal: T(S, N) = O(S^D) -> devido à expansão da árvore de hipóteses
     *  Espacial: S(S, N) = O(D) -> caminho / altura da árvore com chamadas recursivas
     *                    = O(D x S) -> se guardasse cada array de cada chamada recursiva
     */
}

#include <gtest/gtest.h>

TEST(TP2_Ex3, hasBFChangeCanonical) {
unsigned int C[] = {1,2,5,10};
unsigned int Stock[] = {1,1,1,1};
unsigned int n = 4;
unsigned int usedCoins[4];

EXPECT_EQ(changeMakingBacktracking(C,Stock,n,13,usedCoins), true);
EXPECT_EQ(usedCoins[0], 1);
EXPECT_EQ(usedCoins[1], 1);
EXPECT_EQ(usedCoins[2], 0);
EXPECT_EQ(usedCoins[3], 1);

unsigned int Stock2[] = {1,2,4,2};
EXPECT_EQ(changeMakingBacktracking(C,Stock2,n,38,usedCoins), true);
EXPECT_EQ(usedCoins[0], 1);
EXPECT_EQ(usedCoins[1], 1);
EXPECT_EQ(usedCoins[2], 3);
EXPECT_EQ(usedCoins[3], 2);

unsigned int Stock3[] = {10,2,4,2};
EXPECT_EQ(changeMakingBacktracking(C,Stock3,n,10,usedCoins), true);
EXPECT_EQ(usedCoins[0], 0);
EXPECT_EQ(usedCoins[1], 0);
EXPECT_EQ(usedCoins[2], 0);
EXPECT_EQ(usedCoins[3], 1);
}

TEST(TP2_Ex3, hasBFChangeNonCanonical) {
unsigned int C[] = {1,4,5};
unsigned int Stock[] = {2,2,1};
unsigned int n = 3;
unsigned int usedCoins[3];

EXPECT_EQ(changeMakingBacktracking(C,Stock,n,6,usedCoins), true);
EXPECT_EQ(usedCoins[0], 1);
EXPECT_EQ(usedCoins[1], 0);
EXPECT_EQ(usedCoins[2], 1);

EXPECT_EQ(changeMakingBacktracking(C,Stock,n,8,usedCoins), true);
EXPECT_EQ(usedCoins[0], 0);
EXPECT_EQ(usedCoins[1], 2);
EXPECT_EQ(usedCoins[2], 0);

unsigned int Stock2[] = {8,2,1};
EXPECT_EQ(changeMakingBacktracking(C,Stock2,n,7,usedCoins), true);
EXPECT_EQ(usedCoins[0], 2);
EXPECT_EQ(usedCoins[1], 0);
EXPECT_EQ(usedCoins[2], 1);

EXPECT_EQ(changeMakingBacktracking(C,Stock2,n,8,usedCoins), true);
EXPECT_EQ(usedCoins[0], 0);
EXPECT_EQ(usedCoins[1], 2);
EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP2_Ex3, hasNoBFChange) {
unsigned int C[] = {1,2,5,10};
unsigned int Stock[] = {0,1,1,1};
unsigned int n = 4;
unsigned int usedCoins[4];

EXPECT_EQ(changeMakingBacktracking(C,Stock,n,18,usedCoins), false);
EXPECT_EQ(changeMakingBacktracking(C,Stock,n,1,usedCoins), false);
}

#include "exercises.h"

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::overlaps(const Activity &a2) const {
    return (start < a2.finish) && (a2.start < finish);
}

std::vector<Activity> activitySelectionBacktracking(std::vector<Activity> A) {
    return A;
}

#include <gtest/gtest.h>
#include <gmock/gmock.h>

bool noOverlaps(const std::vector<Activity> &acts) {
    for(unsigned int i = 0; i < acts.size(); i++) {
        Activity A1 = acts.at(i);
        for(unsigned int j = i + 1; j < acts.size(); j++) {
            Activity A2 = acts.at(j);
            if(A1.overlaps(A2)) return false;
        }
    }
    return true;
}

TEST(TP2_Ex4, activityScheduling) {
std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
std::vector<Activity> V = activitySelectionBacktracking(A);
EXPECT_EQ(V.size(), 3 );
EXPECT_EQ(noOverlaps(V), true);
}

#ifndef CAL_TP2A_CLASSES_EXERCISES_H
#define CAL_TP2A_CLASSES_EXERCISES_H

#include <vector>

// Ex 1
#define MAZE_WALL 0
#define MAZE_PATH 1
#define MAZE_EXIT 2

class Labyrinth {
public:
    Labyrinth(int values[10][10]);
    void print() const;
    bool findGoal(int x, int y);
    bool solved;
    void find(int x, int y);
    bool find2(int x, int y);
private:
    int labyrinth[10][10];
    bool visited[10][10];
    void initializeVisited();
};

// Ex 2
#define IllegalArgumentException -1

class Sudoku
{
public:
    /**
     * Creates an empty puzzle
     */
    Sudoku();
    /**
     * Initializes a puzzle with initial content.
     * Throws an IllegalArgumentException if any cell has a value out of range or
     * a number is repeated in the same line, column or 3x3 block.
     *
     * @param nums Matrix with the initial cell values (0 for empty cell)
     */
    Sudoku(int nums[9][9]);
    /**
     * Checks if the puzzle has been completely solved.
     */
    bool isComplete() const;
    /**
     * Solves the puzzle.
     * Returns a boolean indicating if the puzzle is possible.
     */
    bool solve();
    /**
     * Determines the multiplicity of the puzzle's solutions.
     * It is a variant of the solve method.
     * Does not change the game's state.
     * Returns:
     *   0 if the puzzle has no solution,
     *   1 if the puzzle has a unique solution,
     *   >1 if the puzzle has two or more solutions (for efficiency reasnos, it does not count all of the solutions and stops on the second one)
     */
    int countSolutions();
    /**
     * Generates a puzzle with a unique solution and filled with as least cells as possible that ensure that the solution is unique.
     */
    void generate();
    /**
	 * Obtains the current of the puzzle (only for reading, not writing!).
	 */
    int **getNumbers();
    /**
     * Prints the solution.
     */
    void print() const;
private:
    /**
     * numbers[i][j] - number that occupies line i, column j (from 0 to 8)
     * 0 means the cell is empty.
     */
    int numbers[9][9];
    /**
     * Information derivable from numbers. Used to accelerate the computations.
     */
    int countFilled;
    bool columnHasNumber[9][10];
    bool lineHasNumber[9][10];
    bool block3x3HasNumber[3][3][10];

    void initialize();
    /**
     * Checks if the cell at line i, column j accepts number n
     */
    bool accepts(int i, int j, int n);
    /**
     * Fills in the cell at line i, column j with number n.
     * Also updates the cell counter.
     */
    void place(int i, int j, int n);
    /**
     * Clears the cell at line i, column j.
     * Returns the previous contents.
     * Also updates the cell counter.
     */
    int clear(int i, int j);
    /**
     * Clears the whole puzzle
     */
    void clear();
	//TODO: Add other methods if needed
};

// Ex 3
bool changeMakingBacktracking(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]);

// Ex 4
class Activity {
public:
    unsigned int start;
    unsigned int finish;
    Activity(unsigned int s, unsigned int f): start(s), finish(f){};
    bool operator==(const Activity &a2) const;
    bool overlaps(const Activity &a2) const;
};
std::vector<Activity> activitySelectionBacktracking(std::vector<Activity> A);

#endif //CAL_TP2A_CLASSES_EXERCISES_H

#include "exercises.h"

#include <limits>
#include <thread>
#include <algorithm>
#include <cmath>

const double MAX_DOUBLE = std::numeric_limits<double>::max();

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

double Point::distance(Point &p) const {
    return sqrt((x-p.x) * (x-p.x)  + (y-p.y) * (y-p.y));
}

double Point::distSquare(Point &p) const {
    return (x-p.x) * (x-p.x)  + (y-p.y) * (y-p.y);
}

bool Point::operator==(const Point &p) const {
    return (x == p.x && y == p.y);
}

std::ostream& operator<<(std::ostream& os, Point &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

Result::Result(double dmin, Point p1, Point p2): dmin(dmin), p1(p1), p2(p2) {
}

Result::Result(): Result(MAX_DOUBLE, Point(0,0), Point(0,0)) {
}

/**
 * Defines the number of threads to be used.
 */
static int numThreads = std::thread::hardware_concurrency();

void setNumThreads(int num) {
    numThreads = num;
}

// Auxiliary functions to sort vector of points by X or Y axis.
static void sortByX(std::vector<Point> &v, int left, int right) {
    std::sort(v.begin( ) + left, v.begin() + right + 1,
              [](Point p, Point q){ return p.x < q.x || (p.x == q.x && p.y < q.y); });
}

static void sortByY(std::vector<Point> &v, int left, int right) {
    std::sort(v.begin( ) + left, v.begin() + right + 1,
              [](Point p, Point q){ return p.y < q.y || (p.y == q.y && p.x < q.x); });
}

Result nearestPoints_BF(std::vector<Point> &vp) {

    int min1, min2, i, j;
    double dis = INT_MAX;

    for (i = 0 ; i < vp.size() ; i++) {
        for (j = 0 ; j < vp.size() ; j++) {
            if (i != j && vp[i].distance(vp[j]) < dis) {
                dis = vp[i].distance(vp[j]);
                min1 = i; min2 = j;
            }
        }
    }

    Result result = Result(dis, vp[min1], vp[min2]);
    return result;
}

Result nearestPoints_BF_SortByX(std::vector<Point> &vp) {

    sortByX(vp, 0, vp.size()-1);
    int min1, min2, i, j;
    double dis = INT_MAX;

    for (i = 1 ; i < vp.size() - 5 ; i++) {
        for (j = i + 1 ; j < i + 6 ; j++ ) {
            if (vp[i].distance(vp[j]) < dis) {
                dis = vp[i].distance(vp[j]);
                min1 = i, min2 = j;
            }
        }
    }

    Result result = Result(dis, vp[min1], vp[min2]);
    return result;
}

Result nearestPoints_DC(std::vector<Point> &vp) {
    return nearestPoints_BF_SortByX(vp);
}

Result nearestPoints_DC_MT(std::vector<Point> &vp) {
    return nearestPoints_BF_SortByX(vp);
}

/// TESTS ///
#include <gtest/gtest.h>
#include <fstream>
#include <time.h>
#include <sys/timeb.h>
#include <random>
#include <stdlib.h>

#define REL_PATH "../TP2b/" // relative path to the tests

/**
 * Auxiliary function to read points from file to vector.
 */
void readPoints(std::string in, std::vector<Point> &vp) {
    std::ifstream is(REL_PATH + in);
    vp.clear();
    if (!is) {
        std::cerr << "Failed to read file " << in << "." << std::endl;
        return;
    }
    while (!is.eof()) {
        double x, y;
        is >> x >> y;
        Point p(x,y);
        vp.push_back(p);
    }
}

/**
 * Auxiliary functions to generate random sets of points.
 */
void shuffle(std::vector<Point> &vp, int left, int right) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, right - left +1);
    for (int i = left; i < right; i++){
        int k = i + dis(gen) % (right - i + 1);
        Point tmp = vp[i];
        vp[i] = vp[k];
        vp[k] = tmp;
    }
}

void shuffleY(std::vector<Point> &vp, int left, int right) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, right - left +1);
    for (int i = left; i < right; i++){
        int k = i + dis(gen) % (right - i + 1);
        double tmp = vp[i].y;
        vp[i].y = vp[k].y;
        vp[k].y = tmp;
    }
}

// Generates a vector of n distinct points with minimum distance 1.
void generateRandom(int n, std::vector<Point> &vp) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, n-1);

    vp.clear();
    // reference value for reference points (r, r), (r, r+1)
    int r = dis(gen);
    vp.push_back(Point(r,r));
    vp.push_back(Point(r,r+1));
    for (int i = 2; i < n; i++)
        if (i < r)
            vp.push_back(Point(i, i));
        else
            vp.push_back(Point(i+1, i+2));
    shuffleY(vp, 2, n-1);
    shuffle(vp, 0, n-1);
}

// Similar, but with constant X.
void generateRandomConstX(int n, std::vector<Point> &vp) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, n-1);

    vp.clear();
    // reference value for min dist
    int r = dis(gen);
    int y = 0;
    for (int i = 0; i < n; i++) {
        vp.push_back(Point(0, y));
        if (i == r)
            y++;
        else
            y += 1 + dis(gen) % 100;
    }
    shuffleY(vp, 0, n-1);
}

/**
 * Auxiliary functions to obtain current time and time elapsed
 * in milliseconds.
 * Something like GetTickCount but portable.
 * It rolls over every ~ 12.1 days (0x100000/24/60/60)
 * Use GetMilliSpan to correct for rollover
 */
int GetMilliCount() {
    timeb tb;
    ftime( &tb );
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}

int GetMilliSpan(int nTimeStart) {
    int nSpan = GetMilliCount() - nTimeStart;
    if (nSpan < 0)
        nSpan += 0x100000 * 1000;
    return nSpan;
}

int testNP(std::string name, std::vector<Point> &points, double dmin, NP_FUNC func, std::string alg) {
    int nTimeStart = GetMilliCount();
    Result res = (func)(points);
    int nTimeElapsed = GetMilliSpan(nTimeStart);
    std::cout << alg << "; " << name << "; " << nTimeElapsed << "; ";
    std::cout.precision(17);
    std::cout << res.dmin << "; " << res.p1 << "; " << res.p2 << std::endl;
    EXPECT_NEAR(dmin, res.dmin, 0.01);
    return nTimeElapsed;
}

/**
 * Runs the given algorithm (func) for an input file (in)
 * and checks the expected result (res).
 * Prints result and performance information.
 */
int testNPFile(std::string in, double dmin, NP_FUNC func, std::string alg) {
    std::vector<Point> pontos;
    readPoints(in, pontos);
    return testNP(in, pontos, dmin, func, alg);
}

int testNPRand(int size, std::string name, double dmin, NP_FUNC func, std::string alg) {
    std::vector<Point> pontos;
    generateRandom(size, pontos);
    return testNP(name, pontos, dmin, func, alg);
}

int testNPRandConstX(int size, std::string name, double dmin, NP_FUNC func, std::string alg) {
    std::vector<Point> pontos;
    generateRandomConstX(size, pontos);
    return testNP(name, pontos, dmin, func, alg);
}

/**
 * Runs the given algorithm for the existent data files.
 */

void testNearestPoints(NP_FUNC func, std::string alg) {
    std::cout << "algorithm; data set; time elapsed (ms); distance; point1; point2" << std::endl;
    int maxTime = 10000;
    if ( testNPFile("Pontos8", 11841.3, func, alg) > maxTime)
        return;
    if ( testNPFile("Pontos64", 556.066, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos1k", 100.603, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos16k", 13.0384, func, alg) > maxTime)
        return;
    /*
    // Uncomment to use more tests
    if (testNPFile("Pontos32k", 1.0, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos64k", 1.0, func, alg) > maxTime)
        return;
    if (testNPFile("Pontos128k", 0.0, func, alg) > maxTime)
        return;
    if (testNPRand(0x40000, "Pontos256k", 1.0, func, alg) > maxTime)
        return;
    if (testNPRand(0x80000, "Pontos512k",  1.0, func, alg) > maxTime)
        return;
    if ( testNPRand(0x100000, "Pontos1M",  1.0, func, alg) > maxTime)
        return;
    if ( testNPRand(0x200000, "Pontos2M",  1.0, func, alg) > maxTime)
        return;
    */
}

TEST(TP3_Ex1, testNP_BF) {
testNearestPoints(nearestPoints_BF, "Brute force");
}

TEST(TP3_Ex1, testNP_BF_SortedX) {
testNearestPoints(nearestPoints_BF_SortByX, "Brute force, sorted by x");
}

TEST(TP3_Ex1, testNP_DC) {
testNearestPoints(nearestPoints_DC, "Divide and conquer");
}

TEST(TP3_Ex1, testNP_DC_2Threads) {
setNumThreads(2);
testNearestPoints(nearestPoints_DC_MT, "Divide and conquer with 2 threads");
}

TEST(TP3_Ex1, testNP_DC_4Threads) {
setNumThreads(4);
testNearestPoints(nearestPoints_DC_MT, "Divide and conquer with 4 threads");
}

TEST(TP3_Ex1, testNP_DC_8Threads) {
setNumThreads(8);
testNearestPoints(nearestPoints_DC_MT, "Divide and conquer with 8 threads");
}