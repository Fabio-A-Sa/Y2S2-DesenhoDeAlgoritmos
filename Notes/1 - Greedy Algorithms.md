# 1 - Algoritmos Gananciosos (*greedy*)

Quando o algoritmo aplica uma heuristica para obter a solução mais favorável, ou seja, o conjunto de subproblemas em que há uma escolha ótima local. Muito usado em problemas de otimização. As cinco premissas que suportam a solução: <br>

1. Conjunto de candidatos, de onde se escolhe a solução;
2. Função de seleção que escolhe o melhor candidato;
3. Função de viabilidade, que verifica se o candidato poderá fazer parte da solução;
4. Função objectivo, que atribui valor a uma solução;
5. Função solução, que determina se e quando a solução é alcançada;

Funcionamento geral do algoritmo:

1. Inicialmente o conjunto de itens está vazio;
2. A cada passo:
   1. Um item é escolhido pela função de seleção;
   2. Se o conjunto solução ficar inviável com esse item, então não voltar a selecioná-lo;
   3. Senão, adicioná-lo ao conjunto solução;

