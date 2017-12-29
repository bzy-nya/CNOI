#include<bits/stdc++.h>
using namespace std;

int n, m;
long long mp  [1005][1005];
long long disA[1005][1005];
long long disB[1005][1005];
long long disC[1005][1005];
long long (*dis)[1005];

int to[4][2] = {
    {1,0}, {-1,0}, {0,1},{0,-1} 
};

struct node{
    int x, y;
    node( int _x, int _y ) 
      : x(_x), y(_y) {}
    bool operator <( const node& F ) const
      { return dis[x][y] > dis[F.x][F.y]; }
};

priority_queue<node> Q;

void SPFA( long long D[][1005], int x, int y ) {
    dis = D;
    for( int i = 1; i <= n; i ++ ) for( int j = 1; j <= m; j ++ ) dis[i][j] = 1e18;
    dis[x][y] = mp[x][y]; Q.push( node( x, y ) ); 
    while( Q.size() ) {
        node N = Q.top(); Q.pop();
        for( int i = 0; i < 4; i ++ ) {
            int tx = N.x + to[i][0];
            int ty = N.y + to[i][1];
            if( tx > n or tx <= 0 or ty > m or ty <= 0 ) continue;
            if( dis[N.x][N.y] + mp[tx][ty] >= dis[tx][ty] ) continue;
        	dis[tx][ty] = dis[N.x][N.y] + mp[tx][ty];
            Q.push( node( tx, ty ) );
        } 
    }
}

int main() {
    int a, b, c; cin >> n >> m >> a >> b >> c;
    for( int i = n; i >= 1; i -- ) for( int j = 1; j <= m; j ++ ) scanf( "%d", &mp[i][j] );

    SPFA( disA, n, a ); SPFA( disB, 1, b ); SPFA( disC, 1, c );
	
    long long ans = 1e18;
    for( int i = 1; i <= n; i ++ ) for( int j = 1; j <= m; j ++ )
      { ans = min( ans, disA[i][j] + disB[i][j] + disC[i][j] - 2ll * mp[i][j] ); }

    cout << ans;
}
