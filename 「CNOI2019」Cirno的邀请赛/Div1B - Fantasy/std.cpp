#include<bits/stdc++.h>
using namespace std;

namespace LCT{
    #define pa fa[x]
    #define ls ch[x][0]
    #define rs ch[x][1]
    int fa [300005];
    int ch [300005][2];
    int val[300005];
    int mi [300005];
    int rev[300005];
    
    void updata(int x) { mi[x] = min( val[x], min( mi[ls], mi[rs] ) ); }
    
    bool isRson(int x) { return ch[pa][1] == x; }
    bool isNson(int x) { return ch[pa][0] != x and ch[pa][1] != x; }
    
    void revers(int x) { rev[x] ^= 1; swap( ls, rs ); }
    void psdown(int x) { if( rev[x] ) revers(ls), revers(rs), rev[x] = 0; }
    
    void rotate(int x) {
        int f = pa, g = fa[f]; bool o = isRson(x), e = !o;
        if( !isNson(f) ) ch[g][ isRson(f) ] = x; fa[x] = g;
        ch[f][o] = ch[x][e], fa[ ch[x][e] ] = f;
        ch[x][e] = f, fa[f] = x;
        updata(f); updata(x);
    }
      
    void retrop(int x) { if( !isNson(x) ) retrop(pa); psdown(x); }
    
    void splay (int x) {
        retrop(x); for( ;!isNson(x); rotate(x) ) if( !isNson(pa) )
          { rotate( ( isRson(x) ^ isRson(pa) ) ? x : pa ); } 
    }
    
    void access(int x) { for( int y = 0; x; y = x, x = pa ) splay(x), rs = y, updata(x); }
    
    void makeroot(int x) { access(x); splay(x); revers(x); }
    int  findroot(int x) { access(x); splay(x); while( ls ) psdown(x), x = ls; return x;  }
    
    void split(int x,int y) { makeroot(x); access(y); splay(y); }
    void link (int x,int y) { pa = y; }
    void cut  (int x,int y) { pa = ch[y][0] = 0; }
    
    #undef pa
    #undef ls
    #undef rs
}

namespace LCT_F{
    using namespace LCT;
    bool same(int x,int y) { makeroot(x); return findroot(y) == x; }
    bool next(int x,int y) { return same( x, y ) and ch[y][0] == x and !ch[x][1]; }
    void link(int x,int y) { if( !same( x, y ) ) LCT::link( x, y ); }
    void cut (int x,int y) { if(  next( x, y ) ) LCT::cut ( x ,y ); }
}

#define Qrange 0, m

namespace PST{
    #define LR L, mid
    #define RR mid + 1, R
    #define mid ( ( L + R ) >> 1 )
    int ls[1 << 22];
    int rs[1 << 22];
    int size[1 << 22];
    int cnt = 0;
    
    int require() { return ++ cnt; }
    
    void updata(int x){ size[x] = size[ ls[x] ] + size[ rs[x] ]; }
    
    int insert(int refer,int L,int R,int p){
        int x = require();
        if( L == R ) return size[x] = 1, x;
        ls[x] = ls[refer]; rs[x] = rs[refer];
        if( p <= mid ) ls[x] = insert( ls[refer], LR, p );
        if( p >  mid ) rs[x] = insert( rs[refer], RR, p );
        return updata(x), x;
    }
    
    int query(int x,int L,int R,int p){
        if( !x or L == R ) return size[x];
        if( p <= mid ) return query( ls[x], LR, p );
        return size[ ls[x] ] + query( rs[x], RR, p );
    }
}

int n, m, q, k;
int E[200005][2];
int H[200005];

//#define __Debug__ 1

int main(int argc,char *argv[]){
    cin >> n >> m >> q >> k;
    for(int i = 0;i <= n;i ++) LCT::val[i] = LCT::mi[i] = 1e9;
    for(int i = 1;i <= m;i ++) cin >> E[i][0] >> E[i][1];
    for(int i = 1;i <= m;i ++){
        int x = E[i][0], y = E[i][1];
        LCT::val[n + i] = LCT::mi[n + i] = i;
        H[i] = H[i - 1];
        if( x == y ){
            H[i] = PST::insert( H[i], Qrange, i );
            continue;
        }
        if( LCT_F::same( x, y ) ){
            int p = LCT::mi[y];
            LCT_F::cut( n + p, E[p][0] );
            LCT_F::cut( n + p, E[p][1] );
            H[i] = PST::insert( H[i], Qrange, p );
        }
        LCT_F::link( n + i, x );
        LCT_F::link( n + i, y );
    }
    static int last_ans = 0;
    while( q -- ){
        int l, r; cin >> l >> r;
        if( k ) l = ( l + last_ans * k ) % m + 1;
        if( k ) r = ( r + last_ans * k ) % m + 1;
        if( l > r ) swap( l, r );
        int ans = PST::query( H[r], Qrange, l - 1 ) - PST::query( H[l - 1], Qrange, l - 1 );
        ans = PST::size[ H[r] ] - PST::size[ H[l - 1] ] - ans;
        ans = r - l + 1 - ans;
        ans = n - ans;
        cout << ( last_ans = ans ) << "\n";
    }
    return 0;
}
