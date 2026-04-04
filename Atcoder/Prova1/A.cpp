#include <iostream>

int main() {
    int m, d; 
    
    if (!(std::cin >> m >> d)) return 0;

    
    if (m == 1 && d == 7) {
        std::cout << "Yes" << std::endl;
    } else if (m == 3 && d == 3) {
        std::cout << "Yes" << std::endl;
    } else if (m == 5 && d == 5) {
        std::cout << "Yes" << std::endl;
    } else if (m == 7 && d == 7) {
        std::cout << "Yes" << std::endl;
    } else if (m == 9 && d == 9) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
