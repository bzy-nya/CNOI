#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int fact[1000005];

int f_pow( int a, int b )
  { int r = 1;
    for( ; b; b >>= 1, a = 1ll * a * a % mod )
      { if( b & 1 ) r = 1ll * r * a % mod; }
    return r; }

int f_com( int a, int b )
  { return 1ll * fact[a] * f_pow( fact[b], mod - 2 ) % mod * f_pow( fact[a - b], mod - 2 ) % mod; }

signed main() {
    int n, k; cin >> n >> k; k = n - k; fact[0] = 1;

    for( int i = 1; i <= n; i ++ ) 
      { fact[i] = 1ll * fact[i - 1] * i % mod; }

    long long ans = 0;
    for( int i = k; i >= 1; i -- ) 
      { ( ans += (((k - i) & 1) ? -1ll : 1ll ) * f_com( k, i ) * f_pow( i, n ) % mod ) %= mod; }

    cout << 1ll * ( ans + mod ) * f_pow( fact[k], mod - 2 ) % mod;
    return 0;
}
