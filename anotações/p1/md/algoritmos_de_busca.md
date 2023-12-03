# Tabela de Símbolos

Uma tabela de símbolos é uma estrutura de dados que armazena pares de chave-valor, permitindo associar valores a chaves para recuperação eficiente de informações.

## Implementações

### Vetor com Chave Indexada

- Índices representam as chaves.
- Valores associados às chaves.
- Não permite chaves duplicadas.
- Inserção com chave pré-existente sobrescreve o valor.
- Chaves em intervalos pequenos.
- Algoritmo de busca: acesso direto.

### Vetor Ordenado

- Conteúdo: Chave + Valor.
- Admite chaves duplicadas.
- Chaves em intervalos grandes.
- Algoritmos de busca: sequencial, binário.

### Árvores Binárias

- Algumas permitem chaves duplicadas.
- Busca e remoção seguem a ordem de inserção.
- Intervalos grandes de chaves.
- Algoritmos de busca: profundidade (DFS), largura (BFS), binária.

## Algoritmos de Busca

### Busca Binária em Vetores Ordenados

- Paradigma da divisão e conquista.
- Divide o vetor ao meio e compara com o elemento desejado.
- Procura na subárvore esquerda se o procurado é menor que o central e na direita se for maior.
- Complexidade: Logarítmica.
- Interpolation Search: Usa uma proporção de busca, podendo falhar se a distribuição das chaves não for boa.

### Árvore Binária de Busca

- Combina flexibilidade de inserção de listas encadeadas com eficiência de busca em vetores ordenados.
- Cada nó interno tem um apontamento à direita e à esquerda.
- Inserção: Elementos menores à esquerda, maiores à direita.
- Remoção: Substitui por um filho único ou adota o menor dos maiores ou maior dos menores em caso de dois filhos.
- Performance depende do balanceamento da árvore.
- Exemplos de árvores balanceadas: AVL, RED-BLACK.
- Melhor caso: Logarítmico.
- Pior caso: Linear.
- Não balanceada: Caso médio é 2logarítmico.