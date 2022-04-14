#include<bits/stdc++.h>

namespace icecream 
  { int a, b, cnt; std::vector<bool>V; }

void init();

std::pair<int,int> Guess(int n, int c);

int Query(int x) {
    const int lim = 2048;
    if( icecream::cnt != lim ) icecream::cnt ++, icecream::V.push_back(0);
    if( x < icecream::a ) return -1;
    if( x > icecream::b ) return 1;
    return 0;
}

int main() {
    
    init();
    
    int t; std::cin >> t;
    int n, k;
    while( t -- ) {
        std::cin >> n >> icecream::a >> icecream::b >> k; 
        icecream::cnt = 0; icecream::V.clear();
        auto P = Guess(n, k);
        if( (int)icecream::V.size() != icecream::cnt ) 
          { std::cout << "3" << std::endl; continue; }
        if( icecream::cnt > k )
          { std::cout << "2" << std::endl; continue; }
        if( icecream::a != P.first or icecream::b != P.second )
          { std::cout << "1" << std::endl; continue; }
        std::cout << "0" << std::endl;
    }
}