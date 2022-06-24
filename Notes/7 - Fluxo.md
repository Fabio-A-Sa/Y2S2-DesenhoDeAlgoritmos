# 7 - Fluxo

Problemas em grafos normalmente dirigidos, em que o peso de cada aresta é apresentada a capacidade. Existe um vértice de entrada de dados (s) e um vértice de saída (t). Para o algoritmo considerado, se existirem mais vértices de entrada, então criar um novo vértice que se liga a estes, com peso infinito de aresta (ou pelo menos com peso igual ao máximo peso das arestas do grafo considerado). Formalmente, o problema de fluxo máximo permite calcular a quantidade máxima que pode sair no último vértice (o fluxo da rede).

O grafo usado tem em cada aresta a capacidade e o fluxo usado no momento, em formato `capacidade/fluxo`. Uma aresta em que a capacidade é igual ao fluxo diz-se saturada. Se não for saturada, então garante-se que capacidade > fluxo.

Algumas definições:

```c++
f(v1, v2) = 100                             // fluxo
c(v1, v2) = 100                             // capacidade
cf(v1, v2) = c(v1, v2) - f(v1, v2) = 0      // capacidade residual
f(v2, v1) = -f(v1, v2) = -100               // fluxo
c(v2, v1) = 0                               // capacidade
cf(v2, v1) = 100                            // neste caso anula a capacidade da aresta
abs(f) = 109                                // fluxo máximo do sistema
```

A solução ótima é garantida quando não existem caminhos de aumento no grafo residual. <br>
O fluxo máximo da rede é igual ao corte mínimo no grafo de capacidade.