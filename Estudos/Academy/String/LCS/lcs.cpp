#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y) {
    int m = x.size();
    int n = y.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }

    return dp[m][n];
}

int main() {
    
    int t, cont=0, r=0, aux_a = 0,aux_b = 0;
    cin >> t;
    string a, b,c;
    while (t--) {
        
        for(int i=0;i<3;i++){
            if(i==0){
                cin >> a;
            }
            else if(i==1){
                cin >> b;
            } 
            else if(i==2){
                cin >> c;


                aux_a = lcs(a, c);
                if(a.size() == 2 && aux_a == 1){
                    aux_a = 0;
                } else {
                    cont += aux_a;
                }

                aux_b = lcs(b, c);
                if(b.size() == 2 && aux_b == 1){
                   aux_b = 0;
                } else {
                    cont += aux_b;
                }
                r = c.size() - cont;
                cout << r << endl;
            }
        }
        aux_a = 0;
        aux_b = 0;
        cont = 0;
        a.clear();
        b.clear();
        c.clear();        
    }
}