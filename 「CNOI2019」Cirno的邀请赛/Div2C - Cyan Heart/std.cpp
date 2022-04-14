#include<bits/stdc++.h>
using namespace std;

namespace STP{
    int V[16][20005];
    void roll(int f) { memcpy( V[f], V[f - 1], sizeof( V[f] ) ); }
    int& at(int f,int x){ return V[f][x]; }
}
int n, V;

int tour[20005];
int stk [20005];
int pnt = 0;

int fa[20005];
int ob[20005][2];
int size[20005];
int son [20005];
vector<int>to[20005];

void dfs_init( int x ) {
    size[x] = 1;
    for( auto N : to[x] ) {
        dfs_init(N);
        size[x] += size[N];
        if( size[N] > size[ son[x] ] ) son[x] = N;
    }
}

int ans[20005];

void dfs_getans( int x, int f ) {
    for(int i = ob[x][0];i <= V;i ++){
        STP::at( f, i ) = max( 
            STP::at( f, i ), 
            STP::at( f, i - ob[x][0] ) + ob[x][1]
        );
        ans[x] = max( ans[x], STP::at( f, i ) );
    }
    for( auto N : to[x] ) if( N ^ son[x] ) {
        STP::roll( f + 1 );
        dfs_getans( N, f + 1 );
    }
    if( son[x] ) dfs_getans( son[x], f );
}

int main(){
	freopen( "5.in", "r", stdin );
	freopen( "5.out", "w", stdout );
    cin >> n >> V;
    for(int i = 1;i <= n;i ++){
        string op; cin >> op;
        if( op == "add" ){
            fa[i] = stk[pnt];  to[ fa[i] ].push_back(i);
            stk[ ++ pnt ] = i;
            cin >> ob[i][0] >> ob[i][1];
        }else pnt --;
        tour[i] = stk[pnt];
    }
    dfs_init(0); dfs_getans(0,0);
    for(int i = 1;i <= n;i ++){
        cout << ans[ tour[i] ] << "\n";
    }
    return 0;
}
