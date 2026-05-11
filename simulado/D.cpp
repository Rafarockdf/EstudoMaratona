#include <bits/stdc++.h>
using namespace std;

int main() {
    int f, u;
    cin >> f >> u;

    int cont = 0;

    vector<int> vet(f);

    for (int i = 0; i < f; i++) {
        int x;
        cin >> x;

        vet[i] = 100 - x;
    }

    sort(vet.begin(), vet.end());

    for (int c : vet) {
        if (u - c >= 0) {
            cont++;
            u -= c;
        } else {
            break;
        }
    }

    cout << cont << endl;
}