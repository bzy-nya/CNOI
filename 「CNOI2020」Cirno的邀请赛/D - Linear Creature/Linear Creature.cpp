#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

vector<int>pre[1000005];
int dp[1000005];

int main(){
    int id, n, m; cin >> id >> n >> m;

    while( m -- )
      { int u, v; cin >> u >> v; 
        pre[u].push_back(v); }

    for( int i = 1; i <= n; i ++ ) 
      { dp[i + 1] = ( dp[i] + pre[i].size() + 1 ) % mod;
        for( auto x : pre[i] ) 
          { ( dp[i + 1] += dp[i] - dp[x] ) %= mod; }
          ( dp[i + 1] += mod ) %= mod;
      }

    cout << ( dp[n + 1] + mod ) % mod;
}
