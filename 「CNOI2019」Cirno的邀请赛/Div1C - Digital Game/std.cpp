#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL que_range( int x ) { return 1ll * x * (x + 1) / 2; }

template<int _size>
struct stamp{
    int A[ _size ];
    int B[ _size ];
    int T[ _size ];
    int cnt = 1;
    bool bind = false;
    
    void Roll() { cnt ++; }
    void Bind() { bind = true; Roll(); }
    void Unte() { bind = false; }
    
    void Set0() { memset( B, 0, sizeof(B) ); Roll(); }
    
    int& operator []( int index ) {
        if( bind ) {
            if( T[index] ^ cnt ) T[index] = cnt, A[index] = B[index];
            return A[index];
        } else return B[ index ];	
    }
};

int block = 500;
int belong[200005];
int beg[405];

struct que{
    int l, r, x, y, id;	
    que() {}
    que( int _id ) { cin >> l >> r >> x >> y; id = _id; }
    bool operator <( que& from ) const
      { return belong[x] == belong[ from.x ] ? y < from.y : x < from.x; }
};

int n, q; 
vector<que> Q;

int c [200005];
int uc[200005];

stamp<200005> pre;
stamp<200005> nxt;
stamp<405> mid;

int bf1( que& x ) { 
    int ans = 0, lst = 0;
    for( int i = x.l; i <= x.r; i ++ ) {
        if( c[i] <= x.y and c[i] >= x.x ) lst ++;
        else lst = 0;
        ans += lst;
    }
    return ans;
}

int bf2( que& x ) {
    int ans = 0;
    for(int i = x.x;i <= x.y;i ++) {
        int p = uc[i];
        if( p < x.l or p > x.r ) continue;
        ans -= que_range( p - pre[p - 1] );
        ans -= que_range( nxt[p + 1] - p );
        nxt[ pre[p - 1] ] = nxt[p + 1];
        pre[ nxt[p + 1] ] = pre[p - 1];
        ans += que_range( nxt[p + 1] - pre[p - 1] + 1 );
    }
    pre.Roll(); nxt.Roll();
    return ans;
}

void updata( int x ) {
    int p = uc[x], b = belong[p];
    if( p ^ beg[b] ) {
        if( pre[p - 1] != beg[b] ) mid[b] -= que_range( p - pre[p - 1] );
        if( p != beg[b + 1] - 1 )nxt[ pre[p - 1] ] = nxt[p + 1];
        else nxt[p] = p, pre[p] = pre[p - 1], nxt[ pre[p - 1] ] = p;
    }
    if( p ^ beg[b + 1] - 1 ) {
        if( nxt[p + 1] != beg[b + 1] - 1 ) mid[b] -= que_range( nxt[p + 1] - p );
        if( p != beg[b] ) pre[ nxt[p + 1] ] = pre[p - 1];
        else pre[p] = p, nxt[p] = nxt[p + 1], pre[ nxt[p + 1] ] = p;
    }
    if( p != beg[b] and p != beg[b + 1] - 1 and pre[p - 1] != beg[b] and nxt[p + 1] != beg[b + 1] - 1 ) 
        mid[b] += que_range( nxt[p + 1] - pre[p - 1] + 1 );
}

LL ans[200005];

int main(){
    cin >> n >> q; 
    
    for(int i = 1;i <= n;i ++) {
        cin >> c[i]; uc[ c[i] ] = i;
        belong[i] = i / block + 1;
        if( belong[i] > belong[i - 1] ) beg[ belong[i] ] = i;
    }
    if( beg[ belong[n] ] == n ) belong[n] --;
    beg[ belong[n] + 1 ] = n + 1; belong[ n + 1 ] = belong[n] + 1;
    
    for(int i = 0;i <= n + 1;i ++) pre[i] = i + 1, nxt[i] = i - 1;
    nxt.Bind(); pre.Bind(); mid.Bind();
    
    for(int i = 1;i <= q;i ++) {
        que x = que(i);
        if     ( x.r - x.l <= block * 2 ) ans[i] = bf1( x );
        else if( x.y - x.x <= block * 2 ) ans[i] = bf2( x ); 
        else Q.push_back( x );
    }
    sort( Q.begin(), Q.end() );
    int pt = 0;
    for(int i = 1;i < belong[n];i ++) {
        int r = beg[i + 1] - 1;
        
        nxt.Unte(); pre.Unte(); mid.Unte();
        for(int j = 0;j <= n + 1;j ++) pre[j] = j + 1, nxt[j] = j - 1; mid.Set0();
        
        while( pt < Q.size() and belong[ Q[pt].x ]  == i ) {
            auto &P = Q[pt];
            
            nxt.Unte(); pre.Unte(); mid.Unte();
            while( r < P.y ) updata( ++ r );
            
            nxt.Bind(); pre.Bind(); mid.Bind();
            for( int j = P.x; j < beg[i + 1]; j ++ ) updata( j );
            
            long long Ans = 0, lst = 0; 
            int bl = belong[ P.l - 1 ] + 1;
            int br = belong[ P.r + 1 ] - 1;
            
            for( int j = P.l; belong[j] < bl; j ++ ) {
                if( c[j] >= P.x and c[j] <= P.y ) lst ++;
                else Ans += que_range( lst ), lst = 0;
            }
            
            for( int j = bl; j <= br; j ++ ) {
                if( nxt[ beg[j] ] == beg[j + 1] - 1 ) lst += beg[j + 1] - beg[j];
                else {
                    lst += nxt[ beg[j] ] - beg[j] + 1;
                    Ans += que_range(lst); Ans += mid[j];
                    lst = beg[j + 1] - pre[ beg[j + 1] - 1 ];
                }
            }
            
            for( int j = beg[br + 1]; j <= P.r; j ++ ) {
                if( c[j] >= P.x and c[j] <= P.y ) lst ++;
                else Ans += que_range( lst ), lst = 0;
            }
            
            Ans += que_range( lst );
            ans[ P.id ] = Ans;
            
            nxt.Roll(); pre.Roll(); mid.Roll();
            pt ++;
        }
    }
    for(int i = 1;i <= q;i ++) cout << ans[i] << "\n";
    return 0;
}
