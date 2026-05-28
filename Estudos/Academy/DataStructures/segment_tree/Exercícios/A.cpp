#include <bits/stdc++.h>
#include <span>
using namespace std;

const int MAX = 100005;
const int INF = 1e9;
int v[MAX];

long long seg[4*MAX];

int build(int no, int i, int j) {
    if(i == j) return seg[no] = v[i];
    int meio = (i+j)/2;
    return seg[no] = min(
        build(2 * no, i, meio),
        build(2 * no + 1, meio + 1, j)
    );
}

int query(int no, int i, int j, int a, int b) {
    if(i > b || j < a) return INF;
    if(i >= a && j <= b) return seg[no];    
    int meio = (i+j)/2;
    return min(query(2*no, i, meio, a, b), query(2*no+1, meio+1, j, a, b));
}

int update(int no, int i, int j, int pos, int val) {
    if(i == j) return seg[no] = val;
    int meio = (i+j)/2;
    if(pos <= meio) return seg[no] = update(2*no, i, meio, pos, val) + seg[2*no+1];
    else return seg[no] = seg[2*no] + update(2*no+1, meio+1, j, pos, val);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, q; 
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        cin >> q;   
        build(1, 0, n-1);
        while(q--){
            int i, j; cin >> i >> j;
            cout << query(1, 0, n-1, i, j) << endl;
        }

    }
}
