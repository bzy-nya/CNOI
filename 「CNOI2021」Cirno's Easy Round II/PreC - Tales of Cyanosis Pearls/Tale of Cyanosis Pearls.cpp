#include<bits/stdc++.h>
using namespace std;

int n;
int c[1005][1005];
vector<int> V[1005];

namespace BIT {
    int c[1005];
    int lowbit( int x ) { return x & -x; }
    void init() { memset( c, 0, sizeof(c) ); }
    void modify( int x, int v )
      { for( ; x <= n; x += lowbit(x) ) c[x] = max( c[x], v ); }
    int query( int x )
      { int r = 0; for( ; x; x -= lowbit(x) ) r = max( r, c[x] ); return r; }
}

int main() {
    cin >> n;
    for( int i = 1; i <= n; i ++ ) for( int j = 1; j <= n; j ++ ) 
      { scanf( "%d", &c[i][j] ); }
    int ans = n * n;
    for( int i = 1; i < n; i ++ ) {
        BIT::init();
        for( int j = 1; j <= n; j ++ ) V[j].clear();
        for( int j = n; j >= 1; j -- ) V[ c[j][i] ].push_back(j);
        for( int j = 1; j <= n; j ++ ) for( auto P : V[ c[j][i + 1] ] )
          { BIT::modify( P, BIT::query( P - 1 ) + 1 ); }
        ans -= BIT::query(n);
    }
    cout << ans;
    return 0;
}
