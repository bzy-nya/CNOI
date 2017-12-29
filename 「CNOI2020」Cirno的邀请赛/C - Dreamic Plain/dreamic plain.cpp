#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N   = 1000005;
int a[1000005];
int b[1000005];

namespace BIT{
    int c[1000005], d[1000005];
    int lowbit( int x ) { return x & -x; }
    void modify( int x, int v, int f ) { for( ;x < N; x += lowbit(x) ) ( c[x] += v * f ) %= mod, d[x] += f; } 
    int query1( int x ) { int r = 0; for( ; x; x -= lowbit(x) ) ( r += c[x] ) %= mod; return r; }
    int query2( int x ) { int r = 0; for( ; x; x -= lowbit(x) ) ( r += d[x] ) %= mod; return r; }
}

namespace SPL{ 
  	vector<int>Que;
    auto Uend = Que.begin();
    auto Ubeg = Que.begin();
    
    void init(){
        sort( Que.begin(),Que.end() );
        Ubeg = Que.begin();
        Uend = unique( Que.begin(),Que.end() );
    }
    
    void insert(int x){ Que.push_back(x); }
    
    int rank(int x)
      { return upper_bound( Ubeg,Uend,x ) - Ubeg + 1; }
    
    int place(int x)
      { return lower_bound( Ubeg,Uend,x ) - Ubeg + 1; }
    
    int size(){ return Uend - Ubeg; }
    
    void clear(){ Que.clear(); }
}


int inv( int x ) {
    int r = 1, b = mod - 2;
    for( ; b; b >>= 1, x = 1ll * x * x % mod )
      { if( b & 1 ) r = 1ll * r * x % mod; }
    return r;
}

int ans = 0;

int main() {
    int n, k; cin >> n >> k;
    for( int i = 1; i <= n; i ++ ) cin >> a[i], SPL::insert( a[i] ); SPL::init();
    for( int i = 1; i <= n; i ++ ) b[i] = SPL::rank( a[i] - 1 );
    ans = a[1]; BIT::modify( b[1], a[1], 1 );
    for( int i = 2; i <= k + 1; i ++ ) {
        ( ans += 1ll * inv(i - 1) * ( 1ll * BIT::query2( b[i] ) * a[i] % mod - BIT::query1( b[i] ) ) % mod ) %= mod;
        ( ans += mod ) %= mod;
        BIT::modify( b[i], a[i], 1 );
    }
    for( int i = k + 2; i <= n; i ++ ) {
        BIT::modify( b[i - k - 1], a[i - k - 1], -1 );
        ( ans += 1ll * inv(k) * ( 1ll * BIT::query2( b[i] ) * a[i] % mod - BIT::query1( b[i] ) ) % mod ) %= mod;
        ( ans += mod ) %= mod;
        BIT::modify( b[i], a[i], 1 );
    }
    cout << ans;
    return 0;
}
