#include<bits/stdc++.h>
using namespace std;

int n, m;
char   s[20000005];
int fail[20000005];

void get_ans() {
    int t = n; n = n + m + 1;
    for( int i = 2; i <= n; i ++ ) {
        fail[i] = 0;
        for( int p = fail[i - 1]; p; p = fail[p] ) if( s[p + 1] == s[i] ) 
          { fail[i] = p + 1; break; }
        if( !fail[i] ) fail[i] = (s[i] == s[1]);
    }
    int ans = 0;
    while( n > t + 1 ) {
        if( fail[n] == 0 ) { cout << "Fake"; return ; }
        n -= fail[n]; ans ++;
    }
    cout << ans;
}

int _main() {
    cin >> n >> m;
    cin >> (s + 1);
    cin >> (s + n + 2);
    s[n + 1] = '#';
    get_ans();
    return 0;
}

int main( int argc, char *argv[] ) {
    for( int i = 1; i <= 30; i ++ ) {
        string s = string(argv[1]) + "\\" + to_string(i) + ".in";
        string t = string(argv[1]) + "\\" + to_string(i) + ".out";
        cerr << s << "\n";
        cerr << t << "\n";
        freopen( s.c_str(), "r", stdin );
        freopen( t.c_str(), "w", stdout );
        _main();
        fclose(stdin);
        fclose(stdout);
    }
}