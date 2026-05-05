#include <bits/stdc++.h>
using namespace std;
int main() {
    string x, aux;
    int cont,aux_cont;
    cin >> x;
    cont = x.size();
    aux_cont = x.size();
    aux = x[0];
    for(int i = 1; i < aux_cont; i++) {
        aux = aux + x[i];
        if(aux[i-1] != x[i]) {
            cont++;
            
        } else {
            cout << aux << endl;
            cout << cont << endl;
            aux = "";
            aux = x[i];
        }
    }
    cout << aux_cont << endl;
    cout << cont << endl;
    return 0;
}
