#include<bits/stdc++.h>
using namespace std;

int n, m;
int c[100005];

int get_ans( int x ) {
    int L = x - 1, R = x;
    long long w = 0, s = 0;
    while( L != 0 or R != n + 1 ) {
        if( R != n + 1 and w * c[R] >= s ) { w ++; s += m; R ++; continue; }
        if( L != 0 and w * c[L] < s ) { w ++; L --; continue; }
        return L ? -1 : 1;
    }
    return 0;
}

int main() {
    freopen( "0.in", "r", stdin );
    freopen( "0.ans", "w", stdout );
    cin >> n >> m;
    for( int i = 1; i <= n; i ++ ) cin >> c[i];
    sort( c + 1, c + n + 1 );
    int l = 1, r = n;
    while( l ^ r ) {
        int mid = (l + r) >> 1;
        if( mid == l ) mid = r;
        if( get_ans(mid) == -1 ) r = mid - 1;
        else l = mid;
    }
    double ans1 = 1.0 * (n - l + 1) * m / n; l = 1;
    while( l ^ r ) {
        int mid = (l + r) >> 1;
        if( mid == r ) mid = l;
        if( get_ans(mid) == 1 ) l = mid + 1;
        else r = mid;
    }
    double ans2 = 1.0 * (n - l + 1) * m / n;
    printf( "%.2lf %.2lf", ans2, ans1 );
    return 0;
}
