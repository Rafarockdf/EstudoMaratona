#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,v,p, c=1;
    vector<pair<int,int>> vet;
    cin >> n;

    int aux = n;

    for(int i=0;i<n;i++){
        cin >> p >> v;
        vet.push_back({p, v});
    }

    cout << vet.size() << endl;
    
    for(int i=0;i<n;i++){
        int r = (c  * vet[i].second) + vet[i].first;
        cout << r << ' ' << c << endl;
        c++;
    }

    return 0;
}