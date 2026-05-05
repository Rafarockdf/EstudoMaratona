#include <bits/stdc++.h>
int main() {
    int n; std::cin >> n;
    std::vector<int> a(n), p(n);
    for(int& i : a) std::cin >> i;
    p[0] = a[0];
    for(int i = 1; i < n; i++) p[i] = p[i-1] + a[i];
    
    int q;
    std::cin >> q;
    while(q--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        int asn = p[r];
        if(l>0) asn -= p[l-1];
        std::cout << asn << std::endl;
    }
    return 0;
}
