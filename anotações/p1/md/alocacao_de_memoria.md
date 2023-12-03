# Memória

## Armazenamento de Dados

### Memória Física

- **Componentes Eletrônicos:**
  - Conservam estados: 1 (alta tensão) e 0 (baixa tensão).
  
- **Computador:**
  - Dados (sistema binário).
  - Lógica (álgebra booleana).
  - Circuitos de computação de estados.

- **Endereços:**
  - Variáveis:
    - Alocadas na memória.
    - Alocação é chamada de endereço.
    - Endereço é dado pelo byte menos significativo (1 byte = 4 bits).
  - Vetores:
    - Cada posição tem um endereço.
    - Cada posição é calculada a partir do endereço inicial.
    - Endereço inicial é apontado pelo identificador do array.
  - Matriz:
    - Funcionam como vetores de vetores.
    - Armazenadas de forma contínua.

- **Ponteiros:**
  - Variáveis capazes de armazenar e manipular endereços de memória.
  - Indicado pelo símbolo *.
  - Sintaxe: `TIPO *ponteiro`.
  - Tamanho fixo.
  - Pode ser NULL (0).

### Memória para os Processos

- **Processo:**
  - Programa em execução.
  - Possui uma porção da memória.
    - Organizada por segmentos, de endereços maiores para menores.
      - Stack: Variáveis locais, parâmetros de funções e endereços de retorno.
      - Heap: Blocos de memória alocados dinamicamente, a pedido do processo.
      - Data: Variáveis globais e estáticas.
      - Text: Código que está sendo executado.
    - Comando: `size executável`, listando os tamanhos de seção e tamanho total de arquivos binários.

- **Alocação:**
  - Estática:
    - Data: Armazena variáveis globais e locais declaradas e não modificadas explicitamente.
  - Automática:
    - Stack: Armazena variáveis locais e parâmetros de funções, assim como endereços de retorno.
      - Alocação e desalocação de forma automática.
      - Tempo de vida: Existência da função.
      - Tamanho: Limitado pelo SO.
    - Alocação de Variáveis:
      - Cada tipo tem um tamanho.
      - Automática: Tamanho e quantidade separados no chamamento da função e liberado após o término da função.
        - Para tipos primitivos, estruturas de dados e registros.
  - Dinâmica:
    - Alocada durante a execução.
    - Tamanhos maiores do que a stack permite.
    - No heap de cada processo.
    - Organiza os dados que se modificam a cada entrada (estruturas de dados).
    - `sizeof`: Computa o tamanho dos operadores, retornando o tamanho em bytes.
    - `malloc`: Aloca uma quantidade de bytes, retornando um ponteiro.
    - `free`: Libera um espaço alocado dinamicamente, apontado por um ponteiro.
    - `calloc`: Aloca memória para um array de determinado tamanho, inicializando a memória com zero.
    - `realloc`: Altera o tamanho da memória apontada por um ponteiro, não afetando o conteúdo.

- **Alocação Dinâmica de uma Matriz:**
  - 1 ponteiro para o início da matriz.

- **Alocação Dinâmica de uma Matriz (Vetores):**
  - 1 ponteiro para ponteiros.