# 1 - Algoritmos Gananciosos (*greedy*)

Quando o algoritmo aplica uma heuristica para obter a solução mais favorável ou uma boa aproximação desta, ou seja, o conjunto de subproblemas em que há uma escolha ótima local. Muito usado em problemas de otimização. As cinco premissas que suportam a solução: <br>

- [x] Conjunto de candidatos, de onde se escolhe a solução;
- [x] Função de seleção que escolhe o melhor candidato;
- [x] Função de viabilidade, que verifica se o candidato poderá fazer parte da solução;
- [x] Função objectivo, que atribui valor a uma solução;
- [x] Função solução, que determina se e quando a solução é alcançada;

#### Funcionamento geral do algoritmo:

1. Inicialmente o conjunto de itens está vazio;
2. A cada passo:
   1. Um item é escolhido pela função de seleção;
   2. Se o conjunto solução ficar inviável com esse item, então não voltar a selecioná-lo;
   3. Senão, adicioná-lo ao conjunto solução;
   
## Exemplos de algoritmos: <br>

### 1 - Dado um conjunto de moedas `const vector<int> &coins` e um troco `total`, retornar o menor número de moedas que prefazem o troco: <br>

#### Prova de Optimalidade:

Um sistema de moedas é canónico se o algoritmo ganancioso conseguir uma solução ótima com stock ilimitado. O melhor contraexemplo x situa-se para um dado conjunto de moedas M na gama M[2] + 1 < x < M[-1] + M[-2]. <br>
Exemplo: <br>
````
M = {1, 4, 5}
x pertence a ]5 + 1 , 5 + 4[ ou seja ]6, 9[
x = {7, 8}
para x = 7, o algoritmo ganancioso retorna [5, 1, 1], que é a solução ótima
para x = 8, o algoritmo ganancioso retorna [5, 1, 1] mas o ótimo é [4, 4]
Fica provado assim que o sistema não é canónico
````
#### Código
`````c++
vector<int> extract(int total, const vector<int> &coins) {

    vector<int> solution = {};                                    # Inicialmente o conjunto solução está vazio
    priority_queue<int> sortedCoins(coins.begin(), coins.end());
    int currentAttemp;

    while (total > 0 && !sortedCoins.empty()) {                   # Enquanto a solução não existir
        currentAttemp = sortedCoins.top();                        # Encontra-se o melhor candidato naquela altura
        sortedCoins.pop();
        if (total - currentAttemp >= 0) {                         # Se viável, então acrescenta-se à solução
            solution.push_back(currentAttemp);
            total -= currentAttemp;
        } else continue;
    }

    if (total != 0) solution.clear();
    return solution;
}
`````

### 2 - Dado um conjunto de atividades, com hora de início e hora de fim, encontrar o subconjunto com maior número de atividades não sobrepostas

#### Código
`````c++
vector<Activity> getNonOverlappingActivities(const vector<Activity> &content) {

    vector<Activity> activities(content.begin(), content.end());
    sort(activities.begin(), activities.end(), 
         [](const Activity &a1, const Activity &a2) { return a1.finish < a2.finish;} );
    vector<Activity> solution = {};

    solution.push_back(activities.front());
    int currentTime = solution.front().finish;

    for (const Activity &activity : activities) {
        if (currentTime < activity.start) {
            currentTime = activity.finish;
            solution.push_back(activity);
        }
    }
    return solution;
}
`````

### 3 - Formalização de um problema:

Deve seguir estes critérios:

1. Descrição do input;
2. Descrição do output;
3. Descrição das restrições (constraints);
4. Descrição da função objectivo (objective function);