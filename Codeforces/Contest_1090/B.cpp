#include <bits/stdc++.h>
#include <span>
using namespace std;

int main() {

    int x,r,n;
    
    
    cin >> n;
    for(int i=0;i<n;i++){
        vector<int> vet;
        for(int i=0; i < 7;i++){
            cin >> x;
            vet.push_back(x);

        }
        sort(vet.begin(), vet.end());
        r = accumulate(vet.begin(), vet.begin() + 6, 0);
        
        cout << vet[6] - r << endl;
    }


}