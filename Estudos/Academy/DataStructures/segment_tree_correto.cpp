#include <bits/stdc++.h>
#include <span>
using namespace std;

const int MAX = 100;
int v[MAX];

int seg[4*MAX];

int build(int no, int i, int j) {
    if(i == j) return seg[no] = v[i];
    int meio = (i+j)/2;
    return seg[no] = build(2*no, i, meio) + build(2*no+1, meio+1, j);
}

int query(int no, int i, int j, int a, int b) {
    if(i > b || j < a) return 0;
    if(i >= a && j <= b) return seg[no];
    int meio = (i+j)/2;
    return query(2*no, i, meio, a, b) + query(2*no+1, meio+1, j, a, b);
}

int main() {

}
