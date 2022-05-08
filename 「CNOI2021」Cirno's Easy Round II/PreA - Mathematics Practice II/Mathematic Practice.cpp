#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int inv( int x ) 
  { if( x == 1 ) return 1;
	return 1ll * ( mod - mod / x ) * inv( mod % x ) % mod; }

int main() {
	int n; cin >> n; n -= 2;
	if( n <= 0 ) { return cout << 0, 0; }
	int ans1 = 1;
	int ans2 = 0;
	for( int i = 1; i <= n; i ++ ) ans1 = ans1 * 2 % mod;
	if( !( n & 1 ) ) {
		ans2 = mod - 1;
		for( int i = 1; i <= n / 2; i ++ ) ans2 = 1ll * ans2 * inv(i) % mod;
		for( int i = n / 2 + 1; i <= n; i ++ ) ans2 = 1ll * ans2 * i % mod;
	}
	cout << ( ans1 + ans2 ) % mod << "\n";
	return 0;
}
