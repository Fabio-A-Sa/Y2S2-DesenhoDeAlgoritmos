# 6 - Grafos

## Componentes fortemente conexos

1. Só fazem sentido em grafos dirigidos (com direções entre cada nó). 
2. Colocar na Stack (LIFO) somente os nós que já não têm filhos que ainda não tenham sido explorados.
3. Trabalhar no grafo transposto (todas as setas com o sentido oposto).
4. Retirar os nós por ordem, seguindo operações da stack `top()` e `pop()`, e desenhar todos os filhos de cada nó segundo as arestas de um grafo dirigido transposto;
5. Cada árvore forma um componente fortemente conexo;

## Atividades

