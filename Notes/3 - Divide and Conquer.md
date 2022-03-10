# 3 - Divide and Conquer

Técnica de divisão em problemas menores que podem ser resolvidos através do mesmo método, usando a recursão, e depois combina-se para obter a solução do problema original. Para subproblemas suficientemente pequenos, resolve-se diretamente. <br>

Notas:

1. Os subproblemas devem ser disjuntos, senão usar programação dinâmica;
2. Divisão dos problemas em dimensão similiar para maior eficiência;
3. Devem existir duas ou mais chamadas recursivas;
4. São algoritmos adequados para processamento paralelo;

## Exemplos de algoritmos:

### MergeSort

Ordenar duas subsequências de igual dimensão e juntá-las. `S(n) = O(n)` e `T(n) = O(n log n)` para qualquer caso.

#### Pseudocódigo ilustrativo:

```c++
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
```

#### Complexidade Temporal

A profundidade de recursão é sempre para um dado array de n elementos, `math.ceil(log(2) n`), há também n splits e n merges. O tempo total é na ordem de `T(n) = O(n log n)`.
Para um limiar típico de n = 20, ainda é melhor usar o [Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/) em vez do MergeSort ou do QuickSort. Consiste em percorrer o array e a cada valor de índice i, colocá-lo num índice [0..i] se for menor. Assim garante-se que o subarray [0..i] está sempre ordenado.

### QuickSort

Ordenar elementos maiores e menores que um pivot do array e concatenar. `S(n) = 1` para qualquer caso e `T(n) varia entre O(n^2) no pior caso e O(n log n) nos restantes`, com escolha aleatória do valor de pivot.

### Pesquisa Binária

Dividir o array ordenado em duas partes e escolher aquela que se adequa ao valor escolhido (parte da direita para valores maiores, a esquerda para menores), até descobrir ou o valor (return true) ou um intervalo em que ele poderia estar (return false).
A complexidade temporal é por isso `T(n) = O(log n)`.

## Processamento Paralelo

Com a utilização de cors do processador, é possível fazer um processamento paralelo de várias funções, de forma a maximizar o tempo dispendido no processo. <br>

Instruções em C++:

```c++

```