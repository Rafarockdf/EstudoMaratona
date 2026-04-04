#include <iostream>
#include <string>

int main() {
    std::string s, t; 
    int _s,_t,result;
    std::cin >> s;
    std::cin >> t;


    _s = s.length();

    result = (_s *(_s+1)) / 2;
    
    std::cout << result;
    
    
    return 0;
}
