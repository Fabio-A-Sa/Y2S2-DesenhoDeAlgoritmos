// Created on March, 2022
// @author: Fábio Araújo de Sá

#include <iostream>
#include <vector>
using namespace std;

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