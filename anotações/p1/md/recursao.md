# Recursão

## Definição

- Propriedade de se repetir de forma finita, tendo uma condição de parada.
  - Funções que invocam a si mesmas.
  - Algoritmos complexos em códigos mais compactos.

- Há uma dependência entre os elementos.
  - O atual depende da determinação de um anterior ou posterior.

- Comportamento de Pilha.
  - Acessando o que está no topo e, no fim, liberando o espaço do topo.
  - Retoma a execução de quem a chamou, chegando à base da pilha (empilhamento e desempilhamento).
  - Stacks: Empilhamento de funções.

- Compiladores Eficientes: Otimizações.

## Estrutura da Recursão

- Passo Base (Condição de Parada).
- Passo Indutivo ou Hipótese da Indução (n-1).
  - Cada chamada tem que tender à condição de parada.

## Custo Computacional

- Determinado pela relação de recorrência, ou seja, a profundidade da pilha.

## Estouro de Pilhas

- Recursão de Cauda.
  - Otimização na compilação.