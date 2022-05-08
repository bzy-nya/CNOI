#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int inv( int x )
  { if( x == 1 ) return 1;
    return 1ll * ( mod - mod / x ) * inv( mod % x ) % mod; } 

int dp[1005];
int dt[1005];

int main() {
    int n, k; cin >> n >> k;
    if( n >= k )
      { for( int i = 1; i <= k; i ++ ) cout << inv(k) << " "; }
    else {
        dp[1] = 1;
        for( int i = 1; i <= n; i ++ ) {
            int invk = inv(i);
            for( int j = 1; j <= k; j ++ ) dp[j] = ( dp[j] + dp[j - 1] ) % mod;
            for( int j = 1; j <  i; j ++ ) dt[j] = ( dp[j] + dp[k] - dp[k - i + j] ) % mod;
            for( int j = i; j <= k; j ++ ) dt[j] = dp[j] - dp[j - i];
            for( int j = 1; j <= k; j ++ ) dt[j] = 1ll * ( dt[j] + mod ) * invk % mod;
            memcpy( dp, dt, sizeof(dp) );
        }
        for( int i = 1; i <= k; i ++ ) cout << dp[i] << " ";
    }
}
