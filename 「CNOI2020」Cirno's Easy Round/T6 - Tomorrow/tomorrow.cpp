#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int phi [1000005];

int main() {
	long long n, sq, ans = 0; cin >> n; sq = sqrt(n);
	
	for( long long i = 2; i <= sq; i ++ ) 
	  { if( !phi[i] ) { 
            phi[i] = i - 1;
            
            for( int j = 2; j <= sq / i; j ++ ) if( phi[j] and ! phi[i * j] ) 
			  { phi[j * i] = phi[j] * ( j % i ? i - 1 : i ); }
			  
			long long x = 0, p = n / i;
			while( p ) p /= i, x += p;
			
			( ans += x * phi[i] % mod ) %= mod;
      } }
	
	cout << ans;
	
	return 0;
} 
