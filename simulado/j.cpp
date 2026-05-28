#include <bits/stdc++.h>
#include <span>
using namespace std;

int main() {
    int n, d;
    bool y = true;
    int cont;
    int cont2;
    vector<pair<int,int>> vet;
    int dia_atual = 1;
    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        int p;
        cin >> p;
        vet.push_back({p, 0});
    }
    while(dia_atual <= 201){
        for (auto& x : vet) {
            if(x.first == 0 and x.second != d){
                x.second--;
            } else if(x.first == 0 and x.second == d){
                cont++;
            } else if(x.first == 0 and x.second == 0){
                x.first = 1;
                vet.erase(vet.begin() + 2);
            } else if(x.first == 1 and x.second != d){
                x.second++;
            } else if(x.first == 1 and x.second == d){
                cont++;
            } else if(x.first == 1 and x.second > d){
                cont2;
            } else if(cont2 == n){
                y = false;
                break;
            }
        }
        dia_atual++;

}
}
