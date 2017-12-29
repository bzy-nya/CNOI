#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int inv(int x)
  { return x == 1 ? 1 : 1ll * (mod - mod / x) * inv(mod % x) % mod; }

int H[3000005];

int _main() {
    int a = 0, b = 0, c = 0, n = 0; cin >> a >> b >> c;
    
    cerr << a << " " << b << " " << c << " " << n << " yes\n";
    n = a + b + c; H[0] = 1;
    
    for( int i = 1; i <= n; i ++ ) H[i] = 1ll * H[i - 1] * i % mod;
    for( int i = 1; i <= n; i ++ ) H[i] = 1ll * H[i - 1] * H[i] % mod;
    
    cout << 1ll * H[a + b + c - 1] * H[a - 1] % mod * H[b - 1]  % mod * H[c - 1] % mod 
            * inv(H[a + b - 1]) % mod * inv(H[b + c - 1]) % mod * inv(H[a + c - 1]) % mod;
    return 0;
}

int main( int argc, char *argv[] ) {
    for( int i = 1; i <= 21; i ++ ) {
        string s = string(argv[1]) + "\\" + to_string(i) + ".in";
        string t = string(argv[1]) + "\\" + to_string(i) + ".out";
        cerr << s << "\n";
        cerr << t << "\n";
        freopen( s.c_str(), "r", stdin );
        freopen( t.c_str(), "w", stdout );
        _main();
        fclose(stdin);
        fclose(stdout);
        
        cin.clear();
    }
}