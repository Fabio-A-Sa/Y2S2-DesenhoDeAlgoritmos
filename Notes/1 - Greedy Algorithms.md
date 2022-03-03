# 1 - Algoritmos Gananciosos (*greedy*)

Quando o algoritmo aplica uma heuristica para obter a solução mais favorável, ou seja, o conjunto de subproblemas em que há uma escolha ótima local. Muito usado em problemas de otimização. As cinco premissas que suportam a solução: <br>

- [x] Conjunto de candidatos, de onde se escolhe a solução;
- [x] Função de seleção que escolhe o melhor candidato;
- [x] Função de viabilidade, que verifica se o candidato poderá fazer parte da solução;
- [x] Função objectivo, que atribui valor a uma solução;
- [x] Função solução, que determina se e quando a solução é alcançada;

Funcionamento geral do algoritmo:

1. Inicialmente o conjunto de itens está vazio;
2. A cada passo:
   1. Um item é escolhido pela função de seleção;
   2. Se o conjunto solução ficar inviável com esse item, então não voltar a selecioná-lo;
   3. Senão, adicioná-lo ao conjunto solução;

Exemplos de algoritmos: <br>

1 - Dado um conjunto de moedas `const vector<int> &coins` e um troco `total`, retornar o menor número de moedas:
`````c++
vector<int> extract(int total, const vector<int> &coins) {

    vector<int> solution = {};                                    # Inicialmente o conjunto solução está vazio
    priority_queue<int> sortedCoins(coins.begin(), coins.end());
    int currentAttemp;

    while (total > 0) {                                           # Enquanto a solução não existir
        currentAttemp = sortedCoins.top();                        # Encontra-se o melhor candidato naquela altura
        sortedCoins.pop();
        if (total - currentAttemp >= 0) {                         # Se viável, então acrescenta-se à solução
            solution.push_back(currentAttemp);
            total -= currentAttemp;
        } else continue;
    }

    if (total < 0) solution.clear();
    return solution;
}
`````