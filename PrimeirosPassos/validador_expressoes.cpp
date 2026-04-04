#include <iostream> // Biblioteca padrão de entrada e saída
#include <string>
#include <algorithm> // para std::remove_if
#include <cctype>
#include <unordered_map>
#include <stdio.h>
#include <string.h>


int main() {
    std::unordered_map<char, int> contagem;
    int tam;
    std::string expressao = R"(


        IF(x > 0){
            x++;
        }

        if(x > 0{
            x++;
        
    [(){})

    )";
    
    expressao.erase(std::remove_if(expressao.begin(), expressao.end(), ::isspace), expressao.end());
    tam = expressao.length();

     for (char c : expressao) {
        if(c == '('){
            contagem[c]++; 
        }
        else if(c == ')'){
            contagem['(']++;
        }
        else if(c == '{'){
            contagem[c]++;
        }
        else if(c == '}'){
            contagem['{']++;
        }
        else if(c == '['){
            contagem[c]++;
        }
        else if(c == ']'){
            contagem['[']++;
        }
            
    }

    // Exibição dos resultados
    for (auto const& [letra, total] : contagem) {
        //std::cout << "'" << letra << "': " << total << std::endl;
        if(total % 2 != 0){
            std::cout << "Sintax Error!" << letra << "': " << total << std::endl;
        }
    }
    return 0;
}
