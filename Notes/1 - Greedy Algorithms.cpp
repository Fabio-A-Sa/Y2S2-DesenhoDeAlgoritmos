#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

template <class T>
void showContent(const vector<T> &content) {
    for (const T &item : content) {
        cout << item << " ";
    } cout << endl;
}

vector<int> extract(int total, const vector<int> &coins) {

    vector<int> solution = {};
    priority_queue<int> sortedCoins = {};
    for (int coin : coins) sortedCoins.push(coin);

    return solution;
}

void coins() {

    vector<int> coins = {1, 1, 1, 2, 2, 2, 2, 5, 5, 10};
    int total = 8;
    vector<int> solution = extract(total, coins);
    showContent(solution);

}

int main () {

    coins();

    return 0;
}