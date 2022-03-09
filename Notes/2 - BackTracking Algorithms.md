# 2 - Algoritmos de Retrocesso (*backtracking*)

É um algoritmo de tentativa e erro, que percorre todo o espaço de estados à procura de um estado-objectivo. Estratégia:
1. Ao chegar a um ponto de escolha, optar por uma delas e continuar a pesquisa;
2. Ao chegar a um beco sem saída, retroceder até ao ponto de escolha e escolher a opção ainda não visitada;

### Exemplos de aplicação:

- [x] Problema do troco com limitação do stock;
- [x] Sudoku;
- [x] 8 rainhas;
- [x] Labirintos;
- [x] DFS (Depth First Search), em grafos;

### Geração de espaços de estado:

Representação conceptual do espaço de solução com base numa árvore binária. Para cada nível da árvore, i, decide-se se está ou não presente o valor array[i]. Cada nó tem a soma do resultado acumulado desde a raiz. <br>
Depois escolhe-se a melhor forma de percorrer a árvore (em ordem, dfs ...).

<br>

Neste caso, no pior cenário o tempo de execução é igual ao espaço de resultados que é exponencial. Então T(n) = O(2^n). Como melhorar? <br>
Por exemplo, fazer uma `poda de pesquisa - pruning`, que acaba com a pesquisa naquele espaço se:
1. A soma selecionada já é maior à soma a prefazer;
2. A soma ainda selecionável é inferior à soma a prefazer;

<br>

Pseudocódigo exemplificativo:

```c++
void exploreNode(Node v) {
    if (isSolution(v)) {
        cout << "Solution at " << v << " node" << endl;
        return;
    } else if (isPromissing(v)) {
        for (const Node& node : v.adjacents) {
            exploreNode(node);
        }
    }
}
```


