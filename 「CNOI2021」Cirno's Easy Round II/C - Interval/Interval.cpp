#include<bits/stdc++.h>
using namespace std;

int n = 1500;
int dp[1505];
int dt[1505];

int max( int a, int b, int c )
  { return max( a, max( b, c ) ); }


int main() {
    for( int i = 1; i <= n; i ++ ) {
        int mi = 1e9;
        for( int j = 1; j <= i; j ++ ) {
            mi = min( mi, max( dt[j - 1], dt[i - j] ) + 1 );
        }
        dt[i] = mi;
        printf( "dt[%d] = %d\n", i, dt[i] );
    }
    for( int i = 2; i <= n; i ++ ) {
        int mi = 1e9, pt = 0;
        for( int j = 1; j <= i; j ++ ) {
            int pre = mi;
            mi = min( mi, max( dp[j - 1], dp[i - j], dt[j - 1] + dt[i - j] ) + 1 );
            if( pre ^ mi ) pt = j;
        }
        dp[i] = mi;
        printf( "dp[%d] = %d(from %d)\n", i, dp[i], i - pt );
    }
    return 0;
}