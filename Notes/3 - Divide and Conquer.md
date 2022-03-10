# 3 - Divide and Conquer

Técnica de divisão em problemas menores que podem ser resolvidos através do mesmo método, usando a recursão, e depois combina-se para obter a solução do problema original. Para subproblemas suficientemente pequenos, resolve-se diretamente. <br>

Notas:

1. Os subproblemas devem ser disjuntos, senão usar programação dinâmica;
2. Divisão dos problemas em dimensão similiar para maior eficiência;
3. Devem existir duas ou mais chamadas recursivas;
4. São algoritmos adequados para processamento paralelo;

## Exemplos de algoritmos:

### MergeSort

Ordenar duas subsequências de igual dimensão e juntá-las. S(n) = O(n) e T(n) = O(n log n) para qualquer caso.

### QuickSort

Ordenar elementos maiores e menores que um pivot do array e concatenar. S(n) = 1 para qualquer caso e T(n) varia entre O(n^2) no pior caso e O(n log n) nos restantes, com escolha aleatória do valor de pivot.

### Pesquisa Binária

Dividir o array ordenado em duas partes e escolher aquela que se adequa ao valor escolhido (parte da direita para valores maiores, a esquerda para menores), até descobrir ou o valor (return true) ou um intervalo em que ele poderia estar (return false).


