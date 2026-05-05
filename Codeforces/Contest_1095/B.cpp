#include <bits/stdc++.h>
int main() {
    int t, n, result = 0; 
    
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        std::cin >> n;

        std::vector<int> lista(n);
        int x = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> lista[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int a = lista[i];
            int b = lista[i+1];
            int diff = abs(a - b); 
            int mdc = std::gcd(a, b); 
            if (diff == mdc) {
                x++;
            } 
        }
        std::cout << x << std::endl;
    }
    
    return 0;
}
