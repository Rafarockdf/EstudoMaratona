# 📚 Documentação Completa de Estudo - Maratona de Programação

## 📑 Índice
1. [Estruturas de Dados](#estruturas-de-dados)
2. [Algoritmos](#algoritmos)
3. [Funções Úteis](#funções-úteis)
4. [Problemas Resolvidos](#problemas-resolvidos)
5. [Recursos e Referências](#recursos-e-referências)

---

## 🔧 Estruturas de Dados

### Vector (Vetor Dinâmico)

Um `vector` é uma estrutura de dados dinâmica que permite armazenar múltiplos elementos do mesmo tipo.

#### Declaração e Inicialização
```cpp
#include <vector>
using namespace std;

vector<int> v;                    // Vector vazio
vector<int> v(5);                 // Vector com 5 elementos (inicializados com 0)
vector<int> v(5, 10);             // Vector com 5 elementos, todos com valor 10
vector<int> v = {1, 2, 3, 4, 5};  // Vector inicializado com valores
```

#### Funções Principais
```cpp
v.push_back(x);      // Adiciona elemento x no final - O(1) amortizado
v.pop_back();        // Remove último elemento - O(1)
v.size();            // Retorna quantidade de elementos - O(1)
v.empty();           // Retorna true se vazio - O(1)
v.clear();           // Remove todos elementos - O(n)
v[i];                // Acessa elemento no índice i - O(1)
v.at(i);             // Acessa com verificação de limites - O(1)
v.front();           // Primeiro elemento - O(1)
v.back();            // Último elemento - O(1)
v.insert(it, x);     // Insere x antes do iterador it - O(n)
v.erase(it);         // Remove elemento no iterador it - O(n)
```

#### Exemplo de Uso
```cpp
vector<int> numeros = {5, 2, 8, 1};
numeros.push_back(10);
cout << numeros.size();  // Output: 5
for(int x : numeros) {
    cout << x << " ";  // Output: 5 2 8 1 10
}
```

---

### Pair (Par de Valores)

Um `pair` armazena dois valores de tipos possivelmente diferentes.

#### Declaração e Inicialização
```cpp
#include <utility>

pair<int, int> p(5, 10);           // Par com dois inteiros
pair<int, string> p = {1, "hello"}; // Par com inteiro e string
auto p = make_pair(5, 10);         // Criando com make_pair
```

#### Acesso aos Elementos
```cpp
p.first;    // Acessa primeiro elemento
p.second;   // Acessa segundo elemento
```

#### Comparação
```cpp
pair<int, int> p1 = {1, 2};
pair<int, int> p2 = {1, 3};
if(p1 < p2) { } // Comparação lexicográfica (primeiro por first, depois second)
```

#### Exemplo com Vector
```cpp
vector<pair<int, string>> pessoas;
pessoas.push_back({25, "João"});
pessoas.push_back({30, "Maria"});
pessoas.push_back({20, "Pedro"});

sort(pessoas.begin(), pessoas.end()); // Ordena por idade (first)

for(auto p : pessoas) {
    cout << p.first << " - " << p.second << endl;
}
```

---

### Map (Mapa/Dicionário Ordenado)

Um `map` armazena pares chave-valor em ordem sorted (pela chave).

#### Declaração e Inicialização
```cpp
#include <map>

map<int, string> mapa;                           // Map vazio
map<int, string> mapa = {{1, "um"}, {2, "dois"}}; // Map inicializado
map<string, int> frequencia;                     // Map com chave string
```

#### Operações Principais
```cpp
mapa[chave] = valor;          // Insere ou atualiza - O(log n)
mapa.insert({chave, valor});  // Insere (não atualiza se existe) - O(log n)
mapa.count(chave);            // Retorna 1 se existe, 0 caso contrário - O(log n)
mapa.find(chave);             // Retorna iterador, end() se não existe - O(log n)
mapa.erase(chave);            // Remove elemento - O(log n)
mapa.size();                  // Quantidade de elementos - O(1)
mapa.empty();                 // Verifica se vazio - O(1)
mapa.clear();                 // Remove todos elementos - O(n)
```

#### Iteração
```cpp
map<int, string> mapa = {{1, "um"}, {2, "dois"}, {3, "três"}};

// Iteração simples
for(auto p : mapa) {
    cout << p.first << " -> " << p.second << endl;
}

// Acesso direto
cout << mapa[1] << endl;  // Output: um

// Com iterador
for(auto it = mapa.begin(); it != mapa.end(); it++) {
    cout << it->first << " -> " << it->second << endl;
}
```

#### Exemplo: Contagem de Frequência
```cpp
map<char, int> frequencia;
string s = "hello world";

for(char c : s) {
    frequencia[c]++;
}

for(auto p : frequencia) {
    cout << p.first << ": " << p.second << endl;
}
// Output:
//   : 1
// d: 1
// e: 1
// h: 1
// l: 3
// o: 2
// r: 1
// w: 1
```

---

### Unordered_Map (Mapa Não Ordenado)

Um `unordered_map` é similar a `map`, mas sem manter ordem (usa hash table).

#### Comparação Map vs Unordered_Map
| Operação | Map | Unordered_Map |
|----------|-----|---------------|
| Insert | O(log n) | O(1) amortizado |
| Delete | O(log n) | O(1) amortizado |
| Search | O(log n) | O(1) amortizado |
| Order | Sim (sorted) | Não |

#### Declaração e Uso
```cpp
#include <unordered_map>

unordered_map<string, int> freq;
freq["hello"]++;
freq["world"]++;

for(auto p : freq) {
    cout << p.first << ": " << p.second << endl;
}
```

#### Quando Usar
- **Map**: Quando precisa de ordem ou precisa de iteração em ordem
- **Unordered_Map**: Quando só precisa fazer lookup rápido (não precisa de ordem)

---

### Deque (Double-Ended Queue)

Uma estrutura que permite inserir/remover dos dois lados eficientemente.

```cpp
#include <deque>

deque<int> dq;
dq.push_back(1);      // Adiciona no final
dq.push_front(0);     // Adiciona no início
dq.pop_back();        // Remove do final
dq.pop_front();       // Remove do início
```

---

### Set e Unordered_Set

Armazenam valores únicos (sem duplicatas).

```cpp
#include <set>

set<int> s;
s.insert(5);
s.insert(3);
s.insert(5);  // Não é adicionado (duplicata)

cout << s.size();  // Output: 2

for(int x : s) {
    cout << x << " ";  // Output: 3 5 (ordenado)
}
```

---

## 🎯 Algoritmos

### 1. Soma de Prefixo (Prefix Sum)

Técnica para responder queries de soma de intervalo em O(1) após pré-processamento O(n).

#### Conceito
- `p[i]` = suma dos elementos de `a[0]` até `a[i]`
- Soma de `a[l..r]` = `p[r] - p[l-1]`

#### Código
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;
    
    vector<int> a(n), p(n);
    for(int& i : a) cin >> i;
    
    // Construir array de prefix sum
    p[0] = a[0];
    for(int i = 1; i < n; i++) {
        p[i] = p[i-1] + a[i];
    }
    
    // Responder queries
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;  // Converter para 0-indexed
        
        int soma = p[r];
        if(l > 0) soma -= p[l-1];
        
        cout << soma << endl;
    }
    
    return 0;
}
```

#### Complexidade
- Pré-processamento: O(n)
- Query: O(1)
- Total: O(n + q)

---

### 2. Segment Tree

Estrutura avançada para queries em intervalo com atualização eficiente.

#### Uso
- Queries de min/max/soma em intervalo
- Atualizar elemento individual
- Complexidade: O(log n) por operação

#### Implementação (Segment Tree de Mínimo)
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int INF = 1e9;
int v[MAX];
long long seg[4*MAX];

// Construir segment tree
int build(int no, int i, int j) {
    if(i == j) return seg[no] = v[i];
    int meio = (i+j)/2;
    return seg[no] = min(
        build(2 * no, i, meio),
        build(2 * no + 1, meio + 1, j)
    );
}

// Query de min em intervalo [a, b]
int query(int no, int i, int j, int a, int b) {
    if(i > b || j < a) return INF;        // Sem sobreposição
    if(i >= a && j <= b) return seg[no];  // Completamente dentro
    
    int meio = (i+j)/2;
    return min(
        query(2*no, i, meio, a, b),
        query(2*no+1, meio+1, j, a, b)
    );
}

// Atualizar elemento em posição pos
int update(int no, int i, int j, int pos, int val) {
    if(i == j) return seg[no] = val;
    
    int meio = (i+j)/2;
    if(pos <= meio) 
        return seg[no] = update(2*no, i, meio, pos, val) + seg[2*no+1];
    else 
        return seg[no] = seg[2*no] + update(2*no+1, meio+1, j, pos, val);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, q; 
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        
        build(1, 0, n-1);  // Construir a árvore
        
        cin >> q;
        while(q--) {
            int i, j; 
            cin >> i >> j;
            cout << query(1, 0, n-1, i, j) << endl;
        }
    }
    return 0;
}
```

#### Complexidade
- Build: O(n)
- Query: O(log n)
- Update: O(log n)

---

### 3. KMP (Knuth-Morris-Pratt)

Algoritmo eficiente para buscar padrão em texto.

#### Conceito
- Encontra todas as ocorrências de um padrão em um texto
- Evita comparações desnecessárias usando informação de falhas
- Complexidade: O(n + m) onde n é tamanho do texto, m é tamanho do padrão

#### LPS (Longest Proper Prefix which is also Suffix)
```cpp
vector<int> lps(vector<char> vet) {
    int n = vet.size();
    vector<int> _lps(n, 0);
    int l = 0, i = 1;

    while(i != n) {
        if(vet[i] == vet[l]) {
            l++;
            _lps[i] = l;
            i++;
        } else {
            if(l != 0) {
                l = _lps[l-1];
            } else {
                i++;
            }
        }
    }
    return _lps;
}
```

#### Busca KMP
```cpp
int kmp(vector<int> _lps, vector<char> padrao, vector<char> busca) {
    int i = 0, j = 0;
    int x = padrao.size();
    int n = busca.size();
    
    while(i < n) {
        if(padrao[j] != busca[i]) {
            if(j != 0) {
                j = _lps[j-1];
            } else {
                i++;
            }
        } else {
            j++;
            i++;
            if(j == x) {
                cout << i - j << endl;  // Posição encontrada
                j = _lps[j-1];
            }
        }
    }
    return 0;
}
```

---

### 4. LCS (Longest Common Subsequence)

Encontra a sequência mais longa comum a duas strings. É um problema clássico de Programação Dinâmica.

#### Conceito
- Uma subsequência é uma sequência que aparece em ordem relativa, mas não necessariamente consecutiva
- Exemplo: "AGGTAB" e "GXTXAYB" têm LCS = "GTAB" (tamanho 4)
- Usamos uma matriz dp onde `dp[i][j]` = tamanho da LCS das primeiras i caracteres da string x e primeiras j caracteres da string y

#### Recorrência
```
Se x[i-1] == y[j-1]:
    dp[i][j] = dp[i-1][j-1] + 1
Senão:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

#### Código Completo
```cpp
#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y) {
    int m = x.size();
    int n = y.size();

    // Criar matriz dp
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Preencher a matriz
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                // Caracteres são iguais
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Caracteres são diferentes, pega o máximo
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];  // Tamanho da LCS
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        
        // Calcular LCS entre a e c
        int lcs_ac = lcs(a, c);
        if(a.size() == 2 && lcs_ac == 1) {
            lcs_ac = 0;
        }
        
        // Calcular LCS entre b e c
        int lcs_bc = lcs(b, c);
        if(b.size() == 2 && lcs_bc == 1) {
            lcs_bc = 0;
        }
        
        // Resultado é o tamanho de c menos o que foi "coberto"
        int resultado = c.size() - lcs_ac - lcs_bc;
        cout << resultado << endl;
    }
    
    return 0;
}
```

#### Exemplo de Execução
```
x = "AGGTAB"
y = "GXTXAYB"

Matriz dp:
       ""  G  X  T  X  A  Y  B
    "" 0   0  0  0  0  0  0  0
    A  0   0  0  0  0  1  1  1
    G  0   1  1  1  1  1  1  1
    G  0   1  1  1  1  1  1  1
    T  0   1  1  2  2  2  2  2
    A  0   1  1  2  2  3  3  3
    B  0   1  1  2  2  3  3  4

LCS = 4 (string "GTAB")
```

#### Reconstrução da String LCS
Se precisar reconstruir a string LCS (não apenas o tamanho):

```cpp
string reconstruct_lcs(string x, string y) {
    int m = x.size();
    int n = y.size();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Reconstruir a string
    string lcs = "";
    int i = m, j = n;
    
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs = x[i - 1] + lcs;  // Adiciona caractere no início
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return lcs;
}
```

#### Complexidade
- Tempo: O(m * n) onde m e n são os tamanhos das strings
- Espaço: O(m * n) para a matriz dp

#### Aplicações
- Comparar similaridade entre DNA
- Diff de arquivos
- Corrigir erros de digitação
- Verificar se uma string é subsequência de outra

---

## 📝 Funções Úteis de String

### Operações Básicas
```cpp
#include <string>
#include <iostream>
using namespace std;

string s = "hello";

// Tamanho
s.size();           // Retorna tamanho
s.length();         // Sinônimo de size()

// Acesso
s[0];               // Primeiro caractere: 'h'
s.front();          // Primeiro caractere: 'h'
s.back();           // Último caractere: 'o'
s.at(0);            // Acesso com verificação: 'h'

// Adição
s += "world";       // Concatenação
s.append(" world"); // Adiciona no final
s.push_back('s');   // Adiciona caractere

// Busca
s.find("ll");       // Retorna posição de "ll" (2), string::npos se não encontrar
s.find('e');        // Busca caractere

// Substring
s.substr(0, 5);     // Retorna substring começando em 0 com 5 caracteres
s.substr(1);        // Retorna substring a partir da posição 1

// Modificação
s.erase(0, 1);      // Remove 1 caractere a partir da posição 0
s.replace(0, 5, "hi"); // Substitui 5 caracteres começando em 0 por "hi"

// Comparação
s == "hello";       // Igualdade
s < "world";        // Comparação lexicográfica

// Inversão
reverse(s.begin(), s.end());

// Conversão
to_string(123);     // Converte int para string
stoi("123");        // Converte string para int
stof("3.14");       // Converte string para float
```

### Exemplos Práticos
```cpp
// Verificar se é palíndromo
string s = "racecar";
string rev = s;
reverse(rev.begin(), rev.end());
if(s == rev) cout << "É palíndromo";

// Contar frequência de caracteres
string s = "hello";
map<char, int> freq;
for(char c : s) freq[c]++;

// Dividir string (split)
string s = "a,b,c,d";
stringstream ss(s);
string token;
while(getline(ss, token, ',')) {
    cout << token << endl;  // a, b, c, d
}
```

---

## 🎓 Problemas Resolvidos

### Atcoder - Prova 1
| Problema | Solução | Descrição |
|----------|---------|-----------|
| A | ✅ | Validação de data especial (mês = dia) |
| B | ✅ | Compressão de string longa |
| D | ✅ | Problema de lógica |

**A.cpp**: Verifica datas especiais (1/7, 3/3, 5/5, 7/7, 9/9)
**B.cpp**: Comprime strings com mais de 10 caracteres no formato `[primeiro][tamanho-2][último]`

---

### Atcoder - Prova 2
| Problema | Solução | Descrição |
|----------|---------|-----------|
| A | ✅ | - |
| B | ✅ | - |
| C | ✅ | - |

---

### Atcoder - Prova 3 (Contest 456)
| Problema | Solução | Descrição |
|----------|---------|-----------|
| A | ✅ | - |
| C | ✅ | - |

---

### Codeforces - Contest 1090
| Problema | Solução | Descrição |
|----------|---------|-----------|
| A | ✅ | Output fixo |
| B | ✅ | - |
| C | ✅ | - |

---

### Codeforces - Contest 1095
| Problema | Solução | Descrição |
|----------|---------|-----------|
| A | ✅ | - |
| B | ✅ | - |

---

### Codeforces - XII Mineira
| Problema | Solução | Descrição |
|----------|---------|-----------|
| D | ✅ | - |
| E | ✅ | - |
| K | ✅ | - |
| L | ✅ | - |

---

### Simulado
| Problema | Solução | Descrição |
|----------|---------|-----------|
| A | ✅ | Verificação de número par > 2 |
| D | ✅ | - |
| E | ✅ | - |
| J | ✅ | - |

**A.cpp**: Verifica se número é par e maior que 2

---

### Primeiros Passos
| Arquivo | Descrição |
|---------|-----------|
| main.cpp | - |
| validador_expressoes.cpp | - |

---

### Estudos - Exercícios

#### Segment Tree Exercícios
- **A.cpp**: Exercício de implementação
- **B.cpp**: Exercício de implementação

#### KMP Exercícios
- **B.cpp**: Exercício de pattern matching

---

## 📚 Resumo de Conceitos Importantes

### Complexidade de Tempo
```
O(1) - Constante
O(log n) - Logarítmica (Busca binária, Segment Tree)
O(n) - Linear
O(n log n) - Linear logarítmica (Merge Sort, Quick Sort)
O(n²) - Quadrática (Bubble Sort, Selection Sort)
O(n³) - Cúbica
O(2^n) - Exponencial
O(n!) - Fatorial
```

### Dicas para Competição
1. **Use `#include <bits/stdc++.h>`** - Inclui todas as bibliotecas padrão
2. **Use `using namespace std;`** - Para não precisar de `std::` a cada uso
3. **Defina constantes**: `const int INF = 1e9;`
4. **Prefira `vector` a arrays** - Mais flexível
5. **Use `auto`** - Para simplificar código
6. **Faça range-based for loops**: `for(int x : v)`
7. **Teste com pequenos exemplos primeiro**
8. **Cuidado com overflow** - Use `long long` quando necessário

### Estrutura de Código Típico
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Seu código aqui
    
    return 0;
}
```

---

## 📖 Recursos e Referências

### Plataformas de Prática
- **AtCoder**: Contests regulares com problemas de qualidade
- **Codeforces**: Maior plataforma de competição de programação
- **LeetCode**: Problemas para entrevista técnica
- **HackerRank**: Tutoriais e problemas

### Tópicos para Estudar Próximo
- [ ] Grafos (BFS, DFS, Dijkstra)
- [ ] Árvores (Binary Search Tree, AVL)
- [ ] Programação Dinâmica avançada
- [ ] Teoria dos Números
- [ ] Geometria Computacional
- [ ] Fluxo em Grafos

### Documentação
- [C++ Reference](https://en.cppreference.com/)
- [AtCoder Tips](https://atcoder.jp/)
- [Competitive Programming Book](https://cses.fi/book/)

---

**Última atualização**: 28 de Maio de 2026

**Status do Aprendizado**: 🟢 Em progresso

