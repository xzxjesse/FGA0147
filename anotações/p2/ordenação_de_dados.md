# Organização de Dados

## Otimização de Buscas

- **Lógica:**
  - Sequencialmente estruturadas, gera previsibilidade.

- **Itens (Arquivos, Pastas):**
  - Chave: Parte do item usada como parâmetro.

## Algoritmos de Ordenação

### Características

- **Complexidade (Espacial, Temporal):**
  - Quadráticos: Simples e suficientes.
  - Linearítimicos: Mais complexos e eficientes.

- **Estabilidade:**
  - Mantém a ordem/posição relativa dos elementos.

- **Adaptatividade:**
  - Aproveitamento da ordenação pré-existente.

- **Memória Extra:**
  - In-place: Utiliza a própria estrutura, sem memória extra significativa.
  - Não in-place: Utiliza memória e estrutura externa (cópias).

- **Localização:**
  - Interna: Cabe na RAM (memória principal).
  - Externa: Usa memória secundária, ordenada por pedaços (chunks).

### Elementares x Eficientes

- **Elementares:**
  - Custos maiores, mais simples.

- **Eficientes:**
  - Custos menores, mais complexos.
  - Analisar a função custo e o tamanho da entrada.

- **Array x Listas Encadeadas:**
  - Métodos elementares: Lidam bem com todas as implementações.
  - Métodos eficientes:
    - Array (acesso direto).
    - Estruturas encadeadas: Árvores ordenadas.

## Elementares

### Selection Sort

- **Selecionar e Posicionar:**
  - Seleciona o menor item e o posiciona na posição definitiva até percorrer o vetor todo.

- **Complexidade Assintótica:**
  - O(N^2).

- **Adaptatividade:**
  - Não.

- **Estabilidade:**
  - Não, tem trocas com saltos.

- **In-place:**
  - Sim, sem uso de memórias extra significativas nem cópias.

  *É possível fazer de modo estável (sem swap) e com listas encadeadas.*

### Bubble Sort

- **Flutuar os Maiores:**
  - Flutua os elementos do início, trocando pelos maiores para que fiquem no topo (fim), comparado com o adjacente.

- **Função Custo:**
  - (n^2)/2 + (n^2)/2.

- **Complexidade Assintótica:**
  - O(N^2), quadrática.
  - Melhor caso: O(N).

- **Adaptatividade:**
  - Sim, a ordenação diminui o processamento.

- **Stabilidade:**
  - Sim, só faz com elementos adjacentes.

- **In-place:**
  - Sim, sem cópias ou memória externa.

  *Bubble sort faz mais swaps que o selection sort, então não é tão eficiente. Pode ser feito com lista encadeada, sendo sequencial. Shaker sort é mais otimizado (flutua o maior e afoga o menor).*

### Insert Sort

- **Inserir na Posição Adequada:**
  - Percorre a partir do segundo elemento, compara com o antecessor e insere quando necessário, reiniciando o processo.

- **Complexidade Assintótica:**
  - O(n^2).
  - Pior caso: N^2/2.
  - Caso médio: N^2/4.
  - Melhor caso: O(N).

- **Adaptatividade:**
  - Sim, aproveita a ordenação pré-existente.

- **Estabilidade:**
  - Sim, não há trocas com saltos e mantém a ordem.

- **In-place:**
  - Sim, não usa memória significativa nem cópia da estrutura.

  *Não indicado para grandes estradas desordenadas ou invertidas. Mesmo desempenho do bubble. Troca apenas com elementos adjacentes.*

### Shell Sort

- **Extensão do Insertion Sort:**
  - Ordena parcialmente a cada passagem e depois usa o insertion para ordenar.

- **Complexidade Assintótica:**
  - Melhor caso: Entre O(n) e O(n^2), dependendo da sequência utilizada.
  - Caso médio: Sem conhecimento.
  - Pior caso: O(n log n).

- **Adaptatividade:**
  - Sim.

- **Estável:**
  - Não.

- **In-place:**
  - Sim.

## Eficientes

### Merge Sort

- **Dividir em Pequenas Partes, Ordenar, Juntar:**
  - Top-down: Lista inteira, dividir em sub-listas e ir subindo. Quando os subvetores estiverem em tamanho unitário, voltar fazendo o merge.
  - Bottom-up: Merge desde os vetores unitários. Bom para listas encadeadas.

- **Complexidade Assintótica:**
  - O(n log n) - todos os casos.

- **Adaptatividade:**
  - Não.

- **Estável:**
  - Sim, mantém a ordem relativa.

- **In-place:**
  - Não, usa memória extra proporcional a n.

  *Otimizações possíveis: Nos subvetores pequenos, usar o insertion sort, testar se o vetor está ordenado, não usar um vetor auxiliar na função merge.*

  ### Quick Sort

- **Dividir e Conquistar:**
  - Ordena elemento por elemento.

- **Particionamento:**
  - Escolher o elemento pivô.
  - Referência para reorganizar os elementos.
  - Define a posição final dele.
  - Repete o processo.

- **Condições:**
  - Nenhum elemento anterior que o pivô é menor, e nenhum posterior será maior (subvetores ainda não ordenados).

- **Pivô:**
  - Mais à direita do vetor, rearranja todos os outros.

- **Complexidade Assintótica:**
  - Melhor e médio: O(n log n).
  - Pior: (n^2)/2.

- **Adaptatividade:**
  - Não, a ordenação não ajuda no desempenho.

- **Estável:**
  - Não, tem trocas com salto e não mantém a ordem relativa.

- **In-place:**
  - Sim, só usa a recursão (que é proporcional a log n).

  *Mediana de 3: Usa a mediana de uma pequena amostra de itens para escolher o pivô, melhorando o particionamento. Bom para entradas aleatórias. Melhorias: Usar o insertion sort para pequenos vetores, particion