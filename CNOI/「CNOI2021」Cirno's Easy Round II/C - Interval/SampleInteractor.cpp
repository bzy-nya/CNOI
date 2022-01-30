#include<bits/stdc++.h>

int a, b, cnt;

void init();

std::pair<int,int> Guess(int n, int c);

int Query(int x) {
    const int lim = 3000;
    if( cnt != lim ) cnt ++;
    if( x < a ) return -1;
    if( x > b ) return 1;
    return 0;
}

int main() {
    int n, k;
    
    init();
    
    std::cin >> n >> a >> b >> k;
    std::pair<int,int> P = Guess(n, k);

    if( P.first <= 0 or P.second > n or P.first > P.second )
      { std::cout << "Illigal interval [" << P.first << "," << P.second << "].\n"; }
    else if( P.first != a or P.second != b ) 
      { std::cout << "Wrong Answer, the interval is [" << a << "," << b << "] "
                  << ", but you returned [" << P.first << "," << P.second << "].\n"; }
    else std::cout << "Correct.";
    if( cnt > k ) 
      { std::cout << "You queried for " << cnt << " times, but no more than " << k << " times is needed.\n";  }
    return 0;
}