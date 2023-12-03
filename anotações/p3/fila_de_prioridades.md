# Fila de Prioridades

- **Definição:**
  - É uma TAD (Tipo Abstrato de Dados) que comporta-se como uma fila, porém o primeiro elemento é o que possui maior prioridade na fila.

- **Características:**
  - Para grande volume de dados, sem a necessidade de ordenação completa.
  - O foco está na prioridade de determinado elemento.
  
- **Prioridade Máxima:**
  - Maior chave corresponde a maior prioridade.

- **Prioridade Mínima:**
  - Menor chave corresponde a maior prioridade.

- **Estruturas Suportadas:**
  - Vetores e listas encadeadas.
    - Não ordenado:
      - Seleciona o de maior prioridade e coloca no início (Selection Sort).
    - Ordenado:
      - A cada novo item, posiciona comparando com seus antecessores (Insertion Sort).
  - Heap binária:
    - Árvore binária completa.
    - Todos os níveis, exceto o último, estão cheios.
    - Nós do último nível estão mais à esquerda possível.
    - Raiz possui a chave de maior prioridade.
    - Não ordena por completo:
      - Mais próximo da raiz, maior prioridade.
      - Filhos com valores menores ou iguais.
    - Representada por vetor:
      - Representação sequencial.
      é representada por um vetor.
    - Navegação para cima e para baixo:
      - Nó: k.
      - Pai: k/2.
      - Filhos: 2k e 2k+1.
    - Tamanho N em um vetor pq[]:
      - pq[N+1]: pq[1...N].
      - Não utiliza pq[0].
      - Pai: (k-1)/2.
      - Filhos 2k+1 e 2k+2.
    - Interface (manipulação da fila):
      - `PQinit(int maxN)`: Cria a fila com capacidade máxima inicial.
      - `PQempty()`: Testa se está vazia.
      - `PQinsert(Item v)`: Insere elemento.
      - `PQdelmax()`: Retorna e remove o de maior prioridade.

    - **Inserção:**
      - Insere nas folhas (no fim do vetor).
      - Restaura/conserta subindo na heap (bottom-up/swim-fixUp).
      - Flutua a chave maior que o pai, recursivamente, até um pai maior ou a raiz.
      - Complexidade: 1 + logN comparações (O(logN)).

    - **Remoção:**
      - Substitui a raiz por uma folha.
      - Restaura/conserta descendo na heap (top-down/sink-fixDown).
      - Afunda a chave menor, recursivamente, até que os filhos sejam menores.
      - Complexidade: 2logN comparações.

    - **Alterar Prioridade:**
      - Se tem o índice na fila de prioridades:
        - `void PQchange(int k, int valor)`.
      - Sem acesso direto:
        - Lista de índices.

  - **Heap Sort:**
    - Filas de prioridades para ordenar elementos.
    - Construção da heap-ordenada.
      - Topo = maior prioridade.
      - Não há garantia de completa ordenação.
      - Construção da heap por inserção.
        - Varredura da esquerda para direita.
        - FixUp para posicionar na heap.
        - Custo proporcional a 2 ∗ N ∗ log N.
    - Ordenação por remoção.
      - Ordenação por remoção (maior prioridade).
      - Reorganização da fila de prioridades.
      - Cada item removido volta para o vetor original.
    - In-place: Sim.
    - Estável: Não.
    - Adaptativo: Não.

  - **Intro Sort:**
    - Combinação de algoritmos para utilizar as eficiências e evitar as deficiências dos métodos.
    - Complexidade:
      - Pior caso: O(n * logn).
    - In-place: Sim.
    - Estável: Não.
    - Adaptativo: Não.
