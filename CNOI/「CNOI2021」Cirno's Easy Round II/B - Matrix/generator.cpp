#include<bits/stdc++.h>
using namespace std;

// 2 3 1 4

const int mod = 998244353;
const int sml = 1000;
const int N = 100000;
const int K = 114514;

int Rand() { return (rand() << 17) | rand(); }

int main(int argc, char *argv[]) {
    string s = string(argv[1]) + "\\10.in";
    freopen( s.c_str(), "w", stdout );
    srand( time(NULL) );
    
    cout << N << " " << K << "\n";
    for( int i = 1; i <= N; i ++ ) cout << Rand() % mod << " \n"[i == N];
    for( int i = 1; i <= N; i ++ ) cout << Rand() % mod << " \n"[i == N];
    return 0;
}