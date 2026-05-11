#include <bits/stdc++.h>
#include <span>
using namespace std;

vector<int> lps(vector<char> vet){
    int n = vet.size();
    string prefix, sufix;
    prefix = vet[0];
    vector<int> _lps(n, 0);
    int l=0, i=1;

    while(i!=n){
        if(vet[i] == vet[l]){
            l+=1;
            _lps[i] = l;
            i+=1;
        } else{
            if(l!=0){
                l = _lps[l-1];
            } else{
                i+=1;
            }
        }
    }
    return _lps;
}

int kmp(vector<int> _lps, vector<char> padrao, vector<char> busca){
    int i=0,j=0;
    int x = padrao.size();
    int n = busca.size();
    while(i<n){
        if(padrao[j] != busca[i]){
            if(j!=0){
                j = _lps[j-1];
            } else{
                i+=1;
            }
        } else{
            j+=1;
            i+=1;
            if(j==x){
                cout << i - j<< endl;
                j = _lps[j-1];
                
            }
        }
    }
    return 0;
}

int main() {
    vector<char> vet = {'A','B','A','B','C', 'A','B','A','B'};
    std::vector<char> v = {
        'B', 'A', 'B', 'A', 'B', 'A', 'B', 'A', 'B', 'C', 
        'A', 'B', 'A', 'B', 'C', 'A', 'B', 'A', 'B'
    };
    vector<int> _lps;
    _lps = lps(vet);
    kmp(_lps,vet,v);
    //for(int x: _lps) cout << x << endl;
}
