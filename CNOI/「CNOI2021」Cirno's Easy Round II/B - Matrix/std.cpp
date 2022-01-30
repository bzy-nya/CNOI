#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int A[100005];
int B[100005];

int f_pow(int a, int b)
  { int r = 1;
    for( ; b; b >>= 1, a = 1ll * a * a % mod )
      { if(b & 1) r = 1ll * a * r % mod; }
    return r; }

int _main() {
    int n, k; cin >> n >> k;
    if( k == 0 ) { cout << n; return 0; }
    int sumA = 0, sumB = 0;
    for( int i = 1; i <= n; i ++ ) cin >> A[i], ( sumA += A[i] ) %= mod;
    for( int i = 1; i <= n; i ++ ) cin >> B[i], ( sumB += B[i] ) %= mod;
    int sumAB = 0;
    for( int i = 1; i <= n; i ++ ) ( sumAB += 1ll * A[i] * B[i] % mod ) %= mod;
    int ans = 1ll * sumA * sumB % mod * f_pow( sumAB, k - 1 ) % mod;
    cout << (ans + mod) % mod;
    return 0;
}

int main( int argc, char *argv[] ) {
    for( int i = 1; i <= 10; i ++ ) {
        string s = string(argv[1]) + "//" + to_string(i) + ".in";
        string t = string(argv[1]) + "//" + to_string(i) + ".out";
        freopen( s.c_str(), "r", stdin );
        freopen( t.c_str(), "w", stdout );
        _main();
        fclose(stdin);
        fclose(stdout);
    }
}