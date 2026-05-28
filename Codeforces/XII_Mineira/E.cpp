#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    int a,b,cont=0;
    vector<pair<int,int>> vet;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        if(a != b){
            vet.push_back({a, b});
        }
    }
    int tam = vet.size();
    int aux;
    for(int i=0;i<tam;i++){
        for(int j=1;j<tam;j++){
            if(vet[i].first != vet[i].second){
                if(vet[i].first == vet[j].first){
                aux = vet[i].second;
                vet[i].second = vet[j].first;
                vet[j].first = aux;
                cont++;
            } else if(vet[i].second == vet[j].first){
                aux = vet[i].first;
                vet[i].first = vet[j].first;
                vet[i].first = aux;
                cont++;
            } else if(vet[i].first == vet[j].second){
                aux = vet[i].second;
                vet[i].second = vet[j].second;
                vet[j].second = aux;
                cont++;
            }
            else if(vet[i].second == vet[j].second){
                aux = vet[i].first;
                vet[i].first = vet[j].second;
                vet[j].second = aux;
                cont++;
            }
            }
            
        }
    }
    cout << cont << endl;
}