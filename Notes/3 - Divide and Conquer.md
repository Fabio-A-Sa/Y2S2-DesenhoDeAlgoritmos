# 3 - Divide and Conquer

Técnica de divisão em problemas menores que podem ser resolvidos através do mesmo método, usando a recursão, e depois combina-se para obter a solução do problema original. Para subproblemas suficientemente pequenos, resolve-se diretamente. O objectivo é melhorar a eficiência temporal em casos onde é possível subdividir.<br>

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

### Cálculos matemáticos

Calcular `math.pow(x, n)` com T(n) = O(log n) e S(n) = O(log n) com divisão e conquista e mais eficiente possível. Exemplo:

```c++
double power (double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    else {
        double d = power(x, n/2);
        if (n % 2 == 0) return d * d;
        else return x * d * d;
    }
}
```

### Pesquisa Binária

Dividir o array ordenado em duas partes e escolher aquela que se adequa ao valor escolhido (parte da direita para valores maiores, a esquerda para menores), até descobrir ou o valor (return true) ou um intervalo em que ele poderia estar (return false).
A complexidade temporal é por isso `T(n) = O(log n)`.

## Processamento Paralelo

Com a utilização de K núcleos do processador, é possível fazer um processamento paralelo de várias funções, de forma a maximizar o tempo dispendido no processo em K vezes. <br>

#### Para descobrir o número de cores do processador usado:

```c++
int getCoreNumber() {
    return std::thread::hardware_concurrency();
}
```

#### Exemplo de implementação com MergeSort:

```c++
void Mergesort(int A[], int p, int q, int r, int threads) {
    if (p < r) {
        int q = math.floor((p+q) / 2);
        if (threads > 1) {
            std::thread t ([=]() {                  // Lança a função para outro core
                MergeSort(A, p, q, thread / 2);
            });
            MergeSort(A, q+1, r, threads / 2);
            t.join();                               // Espera que a outra thread termine
        } else {
            MergeSort(A, p, q, 1);
            MergeSort(A, q+1, r, 1);
        }
        Merge(A, p, q, r);
    }
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
```

Nota: [=] significa que o corpo da função pode usar por cópia todas as variáveis locais da função que insere.

