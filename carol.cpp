#include <iostream>
using namespace std;

void printArray(const int a[], int n) {
    
    // uma simples função para mostrar o vector resultado de comprimento n
    for (int i = 0 ; i < n ; i++) {
        cout << *(a+i) << " ";
    } cout << endl;
}

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) {

    /**
     * indexA <- representa o index do valor atualmente em comparação para o vector a
     * indexB <- representa o index do valor atualmente em comparação para o vector b
     * indexC <- representa o index do valor a ser colocado no vector c
     */
    int indexA = 0, indexB = 0, indexC = 0;

    // este ciclo termina quando todos os elementos de um dos vectores (a ou b) forem visitados
    // ou seja, quando o index a comparar é igual ao tamanho do próprio array
    while (indexA < na && indexB < nb) {

        // em C, coloca-se o mínimo entre os dois valores a comparar (porque é ordem decrescente)
        c[indexC] = min(a[indexA], b[indexB]);
        indexC++; // e passa a apontar para o próximo valor a colocar

        if (a[indexA] > b[indexB]) {    // se foi colocado um elemento do vector B
             indexB++;                  // então passa a apontar para o seguinte elemento do vector B
        } else indexA++;                // senão, passa a apontar para o seguinte elemento do vector A
    }

    if (indexA == na) {                 // se foi o vector A que acabou
        
        while (indexB != nb) {          // colocar o resto dos valores de B em C, por ordem
            c[indexC] = b[indexB];
            indexC++; indexB++;
        }

    } else {                            // se foi o vector B que acabou

        while (indexA != na) {          // colocar o resto dos valores de A em C, por ordem
            c[indexC] = a[indexA];
            indexC++; indexA++;
        }
    }
}

int main() {

    cout << "Running some tests" << endl;

    int a[] = {0, 1}; const int sizeA = 2;
    int b[] = {2, 3, 4}; const int sizeB = 3;
    int c[sizeA+sizeB];

    int d[] = {1, 2, 4, 7}; const int sizeD = 4;
    int e[] = {0, 3, 5, 6, 8, 9}; const int sizeE = 6;
    int f[sizeD + sizeE];

    /* Último teste que acerta */
    merge_arrays(d, sizeD, e, sizeE, f);
    printArray(f, sizeD + sizeE);

    /* Primeiro teste que erra */
    merge_arrays(a, sizeA, b, sizeB, c);
    printArray(c, sizeA + sizeB);

    /* Segundo teste que erra */
    merge_arrays(b, sizeB, a, sizeA, c);
    printArray(c, sizeA + sizeB);

    return 0;
}