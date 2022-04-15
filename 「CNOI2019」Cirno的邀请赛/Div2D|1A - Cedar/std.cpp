#include<bits/stdc++.h>
using namespace std;

#define Rep( _i,_s ) for(register int _i = _s;_i;_i = nxt[_i] )
#define N val[V]

int stk[1000005];

int nxt[3000005];
int val[3000005];

int h1[1000005];
int h2[1000005];

int len[1000005];
int ans[1000005];
int cnt, pnt = 0;

template <class temp>
inline void Rd(temp &p){
    p=0;char c;
    while(c=getchar(),c<48);
    do p=p*10+(c&15);
    while(c=getchar(),c>47);
}

inline void add(int &H,int v){
    nxt[ ++ cnt ] = H;
    val[ cnt ] = v;
    H = cnt;
}

void dfs1(){
    Rep( V, h2[ stk[pnt] ] ) if( len[N] <= pnt - 1 ) add( h2[ stk[ pnt - len[N] ] ], N ); h2[ stk[pnt] ] = 0;
    Rep( V, h1[ stk[pnt] ] ) stk[ ++ pnt ] = N, dfs1();
    pnt --;
}

void dfs2(int x){
    stk[ ++ pnt ] ++;
    Rep( V, h2[x] ) ans[N] -= stk[ pnt + len[N] ];
    Rep( V, h1[x] ) dfs2(N); 
    Rep( V, h2[x] ) ans[N] += stk[ pnt + len[N] ];
    pnt --;
}

int main(){
    int n, q; cin >> n >> q;
    for(int i = 2;i <= n;i ++){
        int f; Rd(f);
        add( h1[f], i );
    }
    for(int i = 1;i <= q;i ++){
        int x, k; Rd(x); Rd(k);
        add( h2[x], i ); len[i] = k;
    }
    stk[ ++ pnt ] = 1; dfs1(); memset( stk, 0, sizeof(stk) ); dfs2(1);
    for(int i = 1;i <= q;i ++){
        printf( "%d ", ans[i] - (bool)ans[i] );
    }
    return 0;
}
