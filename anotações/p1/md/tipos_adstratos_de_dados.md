# Tipos Abstratos de Dados (TAD)

## Definição

- Tipos primitivos de dados.
- Estruturas encapsuladas como objetos.
- Características e operações particulares.
- Acessada por uma interface, ocultando as implementações internas.

## Tipos de TAD

### Fila

- Alinhamento em sequência.
- FIFO (First-In-First-Out): O primeiro a entrar é o primeiro a sair.
- Operações:
  - Inserção no fim.
  - Remoção no início.
  - Complexidade constante.
  
#### Implementação com Lista Estática (Vetores)

- Operações constantes.
- Fila vazia: `primeiro == ultimo`.
- Desinfileirar: Remoção no início da fila.
- Enfileirar: Inserção no fim da fila.
- Fila cheia: `ultimo == tamanho_máximo`.
- Lista estática circular: Se a fila estiver cheia, mas com espaços livres, é possível usar lista circular.

#### Implementação com Lista Encadeada

- Inserções no final da fila.
- Remoções no começo.
- Complexidade e tempo constantes.
- Lista duplamente encadeada circular.
- Lista simplesmente encadeada circular modificada.
- Lista simplesmente encadeada com cauda.

### Pilhas

- Empilhamento de tarefas, último a entrar é o primeiro a sair (LIFO - Last-In-First-Out).
- Operações:
  - Criar.
  - Verificar se está vazia.
  - Empilhar.
  - Desempilhar.
  - Espiar (ver o topo sem remover).

#### Implementação com Listas Estáticas (Vetores)

- Complexidade constante e baratas.
- Operações constantes do topo.
  - Topo: Último elemento do vetor.
  - Vazia: Variável auxiliar igual a 0.
  - Espiar: Desempilhar sem sobrescrever o valor do topo.
  - Remoção: Retira o índice do `(variável - 1)`.
  - Desempilhar: Remoção no topo da pilha e ajuste do topo.
  - Inserção: Coloca no topo da pilha e ajuste do topo.
  - Cheia: Não há espaços vazios, a variável auxiliar é igual a `n`.

#### Implementação com Listas Encadeadas

- Utiliza um nó e uma cabeça.
- Operações: Criar, verificar se está vazia, empilhar, desempilhar e espiar.

### Árvores

- Estruturas de dados em ramos conectados, com crescimento para baixo.
- Armazena um conjunto de dados com relações hierárquicas.

#### Definições Importantes

- Grafo: Estuda a relação entre objetos para obter informações. Acíclico, conexo, dirigido e binário.
- Raiz: Primeiro nó.
- Nós Não Terminais: Filho direito, filho esquerdo, pai, avô, tio, irmão, ancestrais, descendentes.
- Folhas/Nós Terminais: Neto.
- Subárvore: Direita e esquerda.
- Níveis: Raiz = 0, filhos da raiz = 1, netos da raiz = 2.
- Altura: Distância máxima entre a raiz e a folha terminal mais distante.
- Profundidade de um Nó: Distância entre o nó e a raiz.
- Árvore Binária: A ordem dos filhos é relevante.

#### Implementações

- Lista simplesmente encadeada: Criar apontadores para cada necessidade.
- Lista estática: Uso de índices para representar os filhos e encontrar o pai.
- Processamento em profundidade (pilha): Pré-ordem, pós-ordem e inordem.
- Processamento em largura (fila): Por níveis.