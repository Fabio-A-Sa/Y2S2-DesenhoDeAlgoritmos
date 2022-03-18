# 4 - Programação dinâmica (*dynamic programming*)

Técnica que permite resolver problemas típicos de recursão economizando tempo, gastando memória, e numa segunda abordagem minimizando o uso dessa mesma memória resolvendo os subproblemas parciais da base (*bottom-up*).

### Exemplo 1: nCk, combinações

A forma recursiva de combinações gasta a maior parte do tempo a calcular valores da ordem iCj que são quase sempre usados mais do que uma vez.

```c++
long combinations(int n, int k) {
    if (k == 0 || k == n) {
        return 1
    } else {
        return combinations(n-1, k) + combinations(n-1, k-1);
    }
}
```

Outra resolução, usando para isso programação dinâmica (poupando recursos, tanto tempo como espaço):

```c++

```