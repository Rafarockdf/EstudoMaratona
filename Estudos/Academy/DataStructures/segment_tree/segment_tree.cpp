#include <bits/stdc++.h>
#include <span>
using namespace std;

// Estrutura do nó
struct No {
    int dado;
    int inicio, fim; // Intervalo representado pelo nó
    No* esq;
    No* dir;

    No(int valor, int start, int end) : dado(valor), inicio(start), fim(end), esq(nullptr), dir(nullptr) {}
};

void emOrdem(No* raiz) {
    if (raiz == nullptr) return;
    emOrdem(raiz->esq);
    cout << raiz->dado << " ";
    emOrdem(raiz->dir);
}

void inicializaArvore(vector<int>& arr, No* raiz) {
    
    
    
    if (raiz->inicio == raiz->fim) {
        raiz->dado = arr[raiz->inicio];
        return;
    }
    int meio = (raiz->inicio + raiz->fim) / 2;
    if(meio % 2 == 0){
        vector<int> sub_v(arr.begin() + raiz->inicio, arr.begin() + meio + 1);
        raiz->inicio = raiz->inicio;
        raiz->fim = meio;
        raiz->esq = new No(0, raiz->inicio, meio);
        raiz->dir = new No(0, meio + 1, raiz->fim);
        inicializaArvore(sub_v, raiz->esq);
        inicializaArvore(arr, raiz->dir);
    }
    raiz->dado = arr[meio];

}



int main() {
    // Criando uma árvore simples: 1(2,3)
    No* raiz = new No(1, 0, 3);
    raiz->esq = new No(2, 0, 1);
    raiz->dir = new No(3, 2, 3);

    cout << "Travessia Em-Ordem: ";
    emOrdem(raiz); // Saída: 2 1 3
    return 0;
}
