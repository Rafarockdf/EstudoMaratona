#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int w;
    string n, r;

    cin >> w;

    for(int i=0;i<w;i++){
        cin >> n;
        if(n.size() > 10){
            
            char primeira = n.front(); 
            
            char ultima = n.back();
            
            r += primeira;
            r += to_string(n.size() - 2);
            r += ultima;
        } else {
            cout << n << endl;
        } 
        cout << r << endl;
        r.clear();
    }



    return 0;
}