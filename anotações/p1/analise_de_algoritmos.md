# Eficiência e Complexidade de Algoritmos

## Conceitos Básicos

- **Eficácia:**
  - Faz o que deve.

- **Eficiência:**
  - Faz o que deve de forma melhor/mais proveitosa.

- **Recursiva != Iterativa:**
  - A implementação recursiva de um algoritmo pode ser diferente e ter desempenho distinto em comparação à implementação iterativa.

## Como Calcular a Eficiência de um Programa

### Tempo de Máquina

- Dependente de muitas variáveis da máquina.

- **Tempo Real:**
  - Tempo total para a execução.

- **Tempo de Usuário (User):**
  - Tempo exclusivo do processo executado.

- **Tempo do Sistema (Sys):**
  - Tempo dedicado pelo sistema à execução do processo.

### Contagem de Instruções Executadas

- Analisa apenas operações relevantes.

- Tendência de comportamento à medida que a entrada cresce.

- Cálculo Aproximado do Custo:
  - Definição da complexidade dos algoritmos.
  - Complexidade de um algoritmo particular.
  - Complexidade de uma classe de algoritmos.

## Função de Custo f(n)

### Tamanho da Instância do Problema

- **Cenários (Temporais):**
  - Melhor: Menor tempo de execução.
  - Médio: Média dos tempos de execução.
  - Pior: Maior tempo de execução.

### Tempo Constante

- Independente do tamanho de entrada, as instruções são executadas em um número fixo de vezes.

- Exemplos:
  - Atribuições.
  - Comparações.
  - Operações aritméticas.
  - Acessos à memória.
  - Comandos de decisão.

### Complexidade Linear

- Tamanho da entrada é diretamente proporcional ao número de operações.

- Exemplo: Anel ou laço de repetição.

### Complexidade Quadrática

- Processamento dos dados em pares, demandando o dobro de tempo.

- Útil para problemas pequenos.

### Complexidade Cúbica

- Exemplo: Multiplicação de matrizes.

- Eficiente para pequenos problemas.

### Complexidade Exponencial

- Verificação de todas as possibilidades e suas combinações (força bruta).

### Complexidade Fatorial

- Pior que a exponencial.

### Complexidade Logarítmica

- Inversa da exponencial.

- O tempo aumenta de forma mais gradual.

- Processa parte da entrada somente.

- Exemplo: Busca binária em vetor ordenado.

### Complexidade Linearítmica

- Divide e conquista.

- Quebra o problema em problemas menores que são resolvidos e junta as soluções para gerar uma nova solução.

## Cálculo Formal

### Análise Assintótica

- Medição formal para calcular aproximadamente a eficiência dos algoritmos.

- Descreve o crescimento de funções de acordo com as entradas.

- Busca de uma função que represente o limite de f(n).

- **Notação O:**
  - Delimita o crescimento máximo.
  - Exemplo: Se f(n) = n^2 + 2n + 1, a complexidade é O(n^2).
  - Compara o crescimento das funções.
  - Encontra o limite superior (g(n) = argumento de O) para a taxa de crescimento (f(n) = função de custo).
  - g(n) domina assintoticamente f(n), mas tem a mesma tendência de crescimento.
  - Revela a equivalência entre os algoritmos (mesma tendência de crescimento).

- **Outras Notações:**
  - **Omega:**
    - Limite inferior para f(n).
  - **Theta:**
    - Limitada superiormente e inferiormente à g(n).