#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int v[MAX];
int seg[4*MAX];

int build(int no, int i, int j) {
    cout << "build(no=" << no << ", i=" << i << ", j=" << j << ")";
    if (i == j) {
        cout << " -> leaf v[" << i << "]=" << v[i] << "\n";
        return seg[no] = v[i];
    }
    cout << "\n";
    int meio = (i + j) / 2;
    int left = build(2*no, i, meio);
    int right = build(2*no+1, meio+1, j);
    seg[no] = left + right;
    cout << "  seg[" << no << "] = " << left << " + " << right << " = " << seg[no] << "\n";
    return seg[no];
}

int query(int no, int i, int j, int a, int b) {
    cout << "query(no=" << no << ", i=" << i << ", j=" << j << ", a=" << a << ", b=" << b << ")";
    if (i > b || j < a) {
        cout << " -> fora do intervalo, retorna 0\n";
        return 0;
    }
    if (i >= a && j <= b) {
        cout << " -> inteiro dentro, retorna seg[" << no << "]=" << seg[no] << "\n";
        return seg[no];
    }
    cout << "\n";
    int meio = (i + j) / 2;
    int left = query(2*no, i, meio, a, b);
    int right = query(2*no+1, meio+1, j, a, b);
    int result = left + right;
    cout << "  soma parcial = " << left << " + " << right << " = " << result << "\n";
    return result;
}

void printArray(int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << (i + 1 < n ? " ": "\n");
    }
}

void printSegmentTree(int n) {
    int used = 1;
    while (used < n) used <<= 1;
    used = 2 * used;
    cout << "Segment tree (seg[1.." << used - 1 << "]):\n";
    for (int i = 1; i < used; i++) {
        cout << "seg[" << i << "]=" << seg[i];
        if (i + 1 < used) cout << ", ";
    }
    cout << "\n";
}

int main() {
    int n = 8;
    int valores[] = {1, 3, 5, 7, 9, 11, 13, 15};

    cout << "Teste da árvore de segmento:\n";
    cout << "Vetor original:\n";
    for (int i = 0; i < n; i++) v[i] = valores[i];
    printArray(n);

    cout << "\nConstruindo árvore de segmento...\n";
    build(1, 0, n - 1);

    cout << "\nÁrvore de segmento construída:\n";
    printSegmentTree(n);

    vector<pair<int,int>> consultas = {{0, 3}, {2, 5}, {4, 7}, {1, 6}};
    for (auto [a, b] : consultas) {
        cout << "\nConsulta soma em [" << a << ", " << b << "]: \n";
        int resposta = query(1, 0, n - 1, a, b);
        cout << "Resultado = " << resposta << "\n";
    }

    cout << "\nConsulta total [0, " << n-1 << "] para validar soma total:\n";
    cout << "Resultado total = " << query(1, 0, n - 1, 0, n - 1) << "\n";
    return 0;
}
