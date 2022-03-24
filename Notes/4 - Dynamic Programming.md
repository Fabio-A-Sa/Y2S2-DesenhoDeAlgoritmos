# 4 - Programação dinâmica (*dynamic programming*)

Técnica que permite resolver problemas típicos de recursão economizando tempo, gastando memória, e numa segunda abordagem minimizando o uso dessa mesma memória resolvendo os subproblemas parciais da base (*bottom-up*). A técnica passa por introduzir uma progressão iterativa de transformações sucessivas de um espaço linear de soluções. <br>

## Técnicas de Programação dinâmica

`1. Top Down (Memoization)`, recursão até ao caso base, onde podemos usar uma matriz de memorização de tamanho máximo N*N, sendo N o maior valor de input possível, para que não haja tantos cálculos ou chamadas recursivas. É um algoritmo lazy, só calcula um valor quando necessita. 
- Vantagens: do problema em papel para o código é mais simples de implementar; poupa memória e número de cálculos; mais fácil de entender;
- Desvantagens: mais naive; continua com o problema da recursividade; ocupa espaço na stack, pois guarda o endereço de retorno;

`2. Bottom-Up (Tabulation)`, encontra todas as soluções parciais (começando nos casos de base) e com eles calcula a solução pedida.
- Vantagens: mais cálculos necessários; é necessário definir uma ordem dos cálculos para ir da base até aos passos mais dependentes; maior dificuldade de implementação; mais difícl de otimizar o espaço e o tempo;
- Desvantagens: utilização do método space saving tree, pois às vezes dá para passar de uma matriz 2D para uma matriz 1D, poupando assim espaço;

### Exemplo 1: nCk, combinações

A forma recursiva de combinações gasta a maior parte do tempo a calcular valores da ordem iCj que são quase sempre usados mais do que uma vez.

```c++
long combinations(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return combinations(n-1, k) + combinations(n-1, k-1);
    }
}
```

Outra resolução, usando para isso memorização (*memoization*) poupando tempo:

```c++
long combinations(int n, int k) {
    static long memory[100][100];       // considerando somente n <= 99
    if (memory[n][k] != 0) {
        return memory[n][k];
    } else {
        long solution;
        if (k == 0 || k == n) {
            solution = 1;
        } else {
            solution = combination(n-1, k) + combinations(n-1, k-1);
        }
        memory[n][k] = solution;
        return solution;
    }
}
```

Outra resolução, usando para isso programação dinâmica, poupando tempo e poupando chamadas recursivas / espaço na stack:

```c++
long combinations(int n, int k) {
    int maxj = n - k;
    long c[1 + maxj];
    for (int j = 0; j <= maxj; j++)
        c[j] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= maxj; j++)
            c[j] += c[j-1];
    return c[maxj];
}
```

### Exemplo 2: O ladrão com a mochila

```c++
void rouba(int n, int m) {
    
    int f[m+1] = {0};
    int g[m+1] = {0};
    int s[m+1] = {0};
    
    for (int i = 1 ; i <= n ; i++) {
        for (int k = s[i] ; k <= m ; k++) {
            if (v[i] + f[k-s[i]] > f[k]) {
                f[k] = v[i] + f[k-s[i]];
                g[k] = i;
            }
        }
    }
    
    for (int i = 1 ; i <= m ; i++) {
        cout << f[i] << " ";
    } cout << endl;
    for (int i = 1 ; i <= m ; i++) {
        cout << g[i] << " ";
    } cout << endl;
}
```

### Exemplo 3: Sequência de Fibonacci

Dá para fazer da forma recursiva tradicional, gastando memória da stack em chamadas recursivas e recalculando várias vezes o mesmo valor:

```c++
int fib(int n) {
    switch (n) {
        case 0: return 0;
        case 1: return 1;
        default: return fib(n-1) + fib(n-2);
    }
}
```

Método segundo a programação dinâmica: utilização de duas variáveis auxiliares e nenhuma chamada recursiva:

```c++
int fib(int n) {
    int a=1 b=0;
    for ( int i = 1 ; i <= n ; i++) { 
        int t = a; 
        a = b; 
        b += t;
    } 
    return b;
}
```

### Exemplo 4: Algoritmo de Bellman-Ford para grafos

```c++
bool bellmanFord(G, s) {
    
    for (int i = 1 ; i < G.nodes.size() ; i++) {
        G.nodes[i].distance = INT_MAX;
        G.nodes[i].path = nullptr;
    }
    
    for (int i = 1 ; i < G.nodes.size() ; i++) {
        for (int j = 0 ; j < G.nodes[i].adjacents ; j++) {
            Edge currentEdge = G.nodes[i].adjacents[j];
            if (currentEdge.w.distance > currentEdge.v.distance + currentEdge.distance) {
                currentEdge.w.distance = currentEdge.v.distance + currentEdge.distance;
                G.nodes[i].path = w;
            }
        }
    }
    
    for (int i = 0 ; i < G.edges.size() ; i++) {
        Edge currentEdge = G.edges[i];
        if (currentEdge.destiny.distance + currentEdge.distance < currentEdge.origin, distance) {
            cerr << "there are cycles of negative weight" << endl;
            return false;
        }
    }
    return true;
}
```