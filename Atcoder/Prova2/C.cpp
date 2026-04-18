#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
int main() {
    std::unordered_map<int, std::vector<int>> lista;
    std::vector<int> vet;
    int n,m;
    int a,b;
    int aux;
    std::cin >> n >> m; 
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        lista[a].push_back(b);
        if(i==0){
            vet.push_back(a);
            aux = b;
        }
    }
    
    //for (const auto& [chave, valor] : lista) { // C++17 structured bindings
        //std::cout << "Chave: " << chave << ", Valor: "<< valor <<std::endl;
        
    //}
    while(true){

        if (lista.find(aux) == lista.end()) {
            std::cout<<aux<<"Yes"<<std::endl;
            break;
        }
        //aux = lista[aux];
        //vet.push_back(lista[aux]);
        
    }
    for(int d : vet){
        std::cout << d << std::endl;
    }
    std::cout << vet.size() << std::endl;
    return 0;
}
