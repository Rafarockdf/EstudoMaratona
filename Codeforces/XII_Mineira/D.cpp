#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int k;
    double r,c = 216.0; 
    int qtd=0;
    cin >> k;
    for(int i = 1; i<=6;i++){
        for(int j = 1; j<=6;j++){
            for(int z = 1; z<=6;z++){
                if(i+j+z == k){
                    qtd++;
                }
            }
        }
    }
    r = qtd / c;
    cout << fixed << setprecision(10) <<  r << endl;
    
}