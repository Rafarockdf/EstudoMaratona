#include <iostream>
#include <cmath>
int main() {
    int m, d, result = 0; 
    
    std::cin >> m >> d;
    result = abs(d - m) + 1;
    std::cout << result << std::endl;
    return 0;
}
