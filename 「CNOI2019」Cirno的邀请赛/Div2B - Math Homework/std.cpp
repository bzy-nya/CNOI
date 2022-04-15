#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int f_pow( int a, int b ) {
    int r = 1;
    for ( ; b; b >>= 1, a = 1ll * a * a % mod )
      { if( b & 1 ) r = 1ll * r * a % mod; }
    return r;
}

int main(){
    int t; cin >> t;
    while( t -- ) {
        int n, val = 0; scanf( "%d", &n );
        for(int i = 1;i <= n;i ++) { int p; scanf( "%d", &p ); val |= p; }
        cout << 1ll * val * f_pow( 2, n - 1 ) % mod << "\n";
    }
    return 0;
}
