#include <bits/stdc++.h>
using namespace std;



int main() {
    
    int n,x,y,z, cont,r=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y >> z;
        cont = x + y + z;
        if(cont >=2){
            r+=1;
        }
        
    }
    cout << r << endl;

    
}