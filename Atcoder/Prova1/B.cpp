#include <iostream>
#include <string>

int main() {
    int linhas, colunas; 
    
    if (!(std::cin >> linhas >> colunas)) return 0;
    std::string top_down(colunas, '#');
    std::string ponto(colunas-2, '.');
    std::cout << top_down << "\n";
    for(int i=0;i<linhas-2;i++){
        std::cout << "#" << ponto << "#\n";
    }
    std::cout << top_down << "\n";
    return 0;
}
