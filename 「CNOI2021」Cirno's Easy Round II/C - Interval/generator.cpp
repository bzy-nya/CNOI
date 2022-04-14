// 1 1 3 5 1
#include<bits/stdc++.h>
using namespace std;

const int T = 5000;
const int N = 1500;
const int K = 20;

int main( int argc, char *argv[] ) {
    srand( time(NULL) );
    string s = string(argv[1]) + "\\11.in";
    freopen( s.c_str(), "w", stdout );
    cout << T << "\n";
    for( int i = 1; i <= T; i ++ ) {
        int n = (int) ( 1.48 * (1 << (rand() % 10 + 10) ) );
        int x = (rand() ^ (rand() << 5)) % n + 1;
        int y = (rand() ^ (rand() << 5)) % n + 1;
        if( x > y ) swap( x, y );
        int k = floor( log2(n) ) + floor( log2( 4.0 * n / 3.0 ) );
        cout << n << " " << x << " " << y << " " << k << "\n";
    }
}