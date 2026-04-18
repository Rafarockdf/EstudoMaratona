#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <set>
int main() {
    int m, d; 
    std::string linha; 
    std::set<int> numerosUnicos;
    std::cin >> m >> d;
    std::cin.ignore();
    bool repetido = false;
    //std::getline(std::cin, linha);
    
    
    

    
    for (int i = 0; i < m; ++i) {
        int roupa;
        std::cin >> roupa;
        
        
        if (numerosUnicos.count(roupa)) {
            repetido = true;
        }
        numerosUnicos.insert(roupa);
    }

    
    if (repetido) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    if (numerosUnicos.size() == d) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
