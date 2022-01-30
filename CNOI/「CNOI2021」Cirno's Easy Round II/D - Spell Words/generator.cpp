#include<bits/stdc++.h>
using namespace std;

// 2 8 10 10

int n;
int m;

string S;
string T;

int Rand() { return rand() ^ ( rand() << 15 ); }

void gen_s_random() {
    for( int i = 1; i <= n; i ++ )
      { S.append( 1, 'a' + ( Rand() % 26 ) ); }
}

void gen_s_binary() {
    for( int i = 1; i <= n; i ++ )
      { S.append( 1, 'a' + ( Rand() % 2 ) ); }
}

void gen_s_extreme() {
    for( int i = 1; i <= n; i ++ )
      { S.append( 1, "ab"[ Rand() % (n - 1) == 0 ] ); }
}

void gen_s_straight() {
    for( int i = 1; i <= n; i ++ )
      { S.append( 1, 'a' ); }
}

void gen_t_random() {
    int p = m;
    while(p) {
        int r = rand() % min( n, m );
        if( r > p ) r = p;
        for( int i = 0; i < r; i ++ )
          { T.append( 1, S[i] ); }
        p -= r;
    }
}

void gen_t_babystep() {
    int p = m;
    while(p) {
        int r = rand() % 3 + 1;
        if( r > p ) r = p;
        for( int i = 0; i < r; i ++ )
          { T.append( 1, S[i] ); }
        p -= r;
    }
}

void gen_t_sqrt() {
    int p = m;
    while(p) {
        int r = rand() % min( n, (int)sqrt(m) );
        if( r > p ) r = p;
        for( int i = 0; i < r; i ++ )
          { T.append( 1, S[i] ); }
        p -= r;
    }
}

void gen_t_fake() {
    int p = m;
    while(p) {
        int r = rand() % min( n, m );
        if( r > p ) r = p;
        if( r == p ) {
            for( int i = 1; i < r; i ++ )
              { T.append( 1, S[n - i - 1] ); }
            T.append( 1, 'a' + ( Rand() % 26 ) );
        } else {
            for( int i = 0; i < r; i ++ )
              { T.append( 1, S[i] ); }
        }
        p -= r;
    }
}

int main(int argc, char *argv[]) {
    srand( time(NULL) );
    string s = string(argv[1]) + "//" + "30.in";
    freopen( s.c_str(), "w", stdout );
    
    n = 1e7; S.reserve(n);
    m = 1e7; T.reserve(m);
    
    gen_s_random();
    gen_t_fake();
    
    cout << n << " " << m << "\n" << S << "\n" << T << "\n";
    return 0;
}