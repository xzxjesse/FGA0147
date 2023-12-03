# Algoritmos de Ordenação

O link fornecido leva a uma playlist do Prof. Bruno Ribas, abordando algoritmos de ordenação. Aqui estão algumas informações sobre os algoritmos mencionados:

## Conceitos Gerais

- **In-place:** Os algoritmos de ordenação in-place operam diretamente nos elementos do vetor, sem a necessidade de memória extra significativa.

- **Estável:** Algoritmos estáveis garantem que itens com chaves idênticas permaneçam na mesma posição relativa no vetor após a ordenação.

## Algoritmos

### Selection Sort

- Percorre o vetor, seleciona o menor elemento e o coloca na posição adequada, incrementando a posição de seleção.

- **Estabilidade:** Instável.

- **In-place:** Sim.

### Bubble Sort

- Percorre o vetor, "flutuando" o menor elemento para o início e "afundando" o maior a cada passada.

- **Estabilidade:** Estável.

- **In-place:** Sim.

- **Comportamento:** Sempre se comporta mal em termos de desempenho, mesmo quando o vetor já está parcialmente ordenado.

### Insertion Sort

- Parte de um elemento do vetor e compara-o com seus adjacentes para posicioná-lo corretamente.

- **Estabilidade:** Estável.

- **In-place:** Sim.

### Shell Sort

- Similar ao Insertion Sort, mas, em vez de comparar apenas com os adjacentes, compara elementos com intervalos maiores.

- **Estabilidade:** Instável.

- **In-place:** Sim.

- **Desempenho:** Bom, mas a complexidade é difícil de calcular.

### Quick Sort

- Divide e rearranja o vetor, escolhendo um elemento como pivô. Todos os maiores ficam à direita, e os menores à esquerda, mesmo que os subvetores não estejam ordenados.

- **Estabilidade:** Instável.

- **In-place:** Sim.

- **Melhoria:** Mediana de três - escolhe um pivô mais próximo da mediana do vetor para melhorar o desempenho.

### Merge Sort

- Divide o vetor ao meio e ordena cada metade. Divide a quantidade necessária para facilitar a ordenação (valores unitários).

- **Estabilidade:** Instável.

- **In-place:** Não.

## Desempenho e Complexidade

- **Complexidade:** Mede o tempo de execução e o espaço ocupado.

- **Medida:** Função de custo ou complexidade f(n).

- **Complexidade Assintótica:** Cálculo aproximado da eficiência do algoritmo.

- **Notação O:** Comparação da tendência de crescimento entre f(n) e g(n). Exclui constantes e foca no maior expoente de n.

- **Exemplos:**
  - O(1): Complexidade constante.
  - O(n): Complexidade linear.
  - O(logn): Complexidade logarítmica.
  - O(nlogn): Complexidade log-linear.
  - O(n²): Complexidade quadrática.
  - O(n³): Complexidade cúbica.
  - O(2ⁿ): Complexidade exponencial.
  - O(n!): Complexidade fatorial.