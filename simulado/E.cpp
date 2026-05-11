#include <bits/stdc++.h>
#include <span>
using namespace std;

int main() {
    int n;
    cin >> n;
    int r,c;
    long long soma;
    map<int, vector<int>> dict;
    for(int i=0; i<n; i++) {
        cin >> r >> c;
        dict[r].push_back(c);
    }
    
    
    for(auto& pair : dict) {

        vector<int>& casas = pair.second;

        sort(casas.begin(), casas.end());

        int meio = casas.size() / 2;

        int x = casas[meio];
        for(int casa : casas) {
            soma += abs((long long)casa - x);
        }
        
    }
    
    
    cout << soma << endl;
}