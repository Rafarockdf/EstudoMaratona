#include <iostream>
#include <string>

int main() {
    std::string s, t,sub,sub_ref; 
    int _s,_t,result,t_i=0,cont=0;
    std::cin >> s;
    std::cin >> t;
    

    _s = s.length();
    _t = t.length();
    result = (_s *(_s+1)) / 2;

    for(int i=0;i<_s;i++){
        for(int j=0;j<_s;j++){
            if(t_i==_t-1){
                t_i = 0;
            }
            if(s[j] == t[t_i]){
                t_i++;
                sub = sub + s[j];
                cont++;
            }
        }
    }
    
    std::cout << result - cont;
    
    
    return 0;
}
