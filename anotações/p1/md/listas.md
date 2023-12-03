# Representação de um Conjunto de Dados

## Listas Estáticas (Arrays)

- Mesmo tipo de dados.
- Espaço consecutivo na RAM.
- Acesso aleatório por um índice = acesso direto.
- Nome aponta para o endereço de memória inicial.
- Tamanho fixo (stack) ou alocado dinamicamente (heap).

### Operações

- **Acesso:**
  - Custo constante.

- **Remoção:**
  - Custo de deslocamento = custo linear.

- **Inserções:**
  - Se não houver deslocamento, sobrescreve o espaço.

### Dificuldades

- Manipulação difícil.

## Listas Encadeadas

### Simplesmente Encadeada

- Conjunto de nós ou células.
- Armazena um (item) e um (link) - o link é um ponteiro para o próximo nó.
- O nó próximo (último) é NULL.

#### Tipos

- **Lista Sem Cabeça:**
  - Tem que ter o endereço do primeiro nó.

- **Lista Com Cabeça:**
  - No lugar da cabeça não tem item, só link.

- **Com Nó Cabeça e Cauda:**

### Duplamente Encadeada

- Multilista.
- Armazena nó anterior e posterior.
- Útil para grandes modificações.
- Anterior do primeiro e posterior do último apontam para NULL.

### Circular

- **Simplesmente Circular:**
  - Último aponta para o primeiro.

- **Duplamente Circular:**
  - Primeiro aponta para o último, e o último aponta para o primeiro.

- **Único Elemento Circular:**
  - Aponta para si mesmo.

- **Cabeça Circular:**
  - O primeiro é o que aponta para o último, e o último é o que aponta para o primeiro.

## Multilista

- Apontamento anterior e próximo são independentes.
- Representação de árvores.

## Vetor de Strings

- Vetor que armazena cadeias de caracteres.

## Vetor de Vetores (Matrizes)

- Matrizes com listas encadeadas.

### Matrizes Esparsas

- Estrutura para representar matrizes com muitos elementos iguais a zero, economizando espaço de armazenamento.