## Algoritmos de Ordenação - Linearítmicos e Lineares

### Linearítmicos (O(n log n))

- **Melhor Custo:** Utilizados em ordenação por comparação da chave.
  
- **Vantagem:** Amplamente aplicáveis.

#### Counting Sort

- Ordena contando as chaves em um vetor auxiliar.
- O índice é determinado pela chave, contando a quantidade de chaves menores.
- Histograma dos números: Distribuição das frequências.
- Cada chave é posicionada na posição definitiva.
- **In-place:** Não.
- **Estável:** Sim.
- **Adaptativo:** Sim.

#### Radix Sort

- Compara a estrutura das chaves, decompondo a chave em subestruturas (por exemplo, unidades, dezenas, centenas).
- A cada iteração/recursão, compara somente parte da chave e ordena parcialmente.
- Operações custosas, compensando para chaves grandes.
- **In-place:** Não.
- **Estável:** Sim.
  
  ##### Métodos de Classificação
  
  1. **LSD (Least Significant Digit):**
     - Ordena estável chaves de comprimento fixo.
     - A partir do dígito menos significativo, da direita para a esquerda.

  2. **MSD (Most Significant Digit):**
     - Ordenação de propósito geral, para chaves com tamanhos variáveis.
     - A partir do dígito mais significativo, da esquerda para a direita.
     - Usa o counting sort (key-indexed counting) e, recursivamente, ordena os sub-vetores de cada caractere.
  
  ##### Complexidade
  - Acessos proporcional a W ∗ N (W: tamanho da chave, N: número de chaves, R: tamanho do alfabeto).
  
### Lineares (O(n))

- **Melhor Custo:** Utilizados em ordenação por comparação da estrutura da chave.

- **Desvantagem:** Mais restritos, sendo necessário conhecimento prévio do intervalo das chaves.

#### Counting Sort (Revisão)

- Ordena contando as chaves em um vetor auxiliar.
- Índice = chave (determina a posição contando a quantidade de chaves menores).
- **In-place:** Sim.
- **Estável:** Sim.
- **Adaptativo:** Sim.