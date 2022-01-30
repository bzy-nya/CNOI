#include<bits/stdc++.h>
using namespace std;

// 5 5 10 10

const int N = 20;
const int M = 20;

int Rand() { return (rand() << 16) | rand(); }

int main(int argc, char *argv[]) {
    srand( time(NULL) );
    while(1) {
        ofstream out1; out1.open( "1.in" );
    //freopen( "0.in", "w", stdout );
        out1 << N << " " << M << "\n";
        for( int i = 1; i <= N; i ++ ) {
            out1 << Rand() % (M + 1) << " \n"[i == N];
        }
    system( ".\\std.exe" );
    system( ".\\qwq.exe" );
    ifstream in1; in1.open("0.out");
    ifstream in2; in2.open("0.ans");
    double a, b; in1 >> a >> b;
    double c, d; in2 >> c >> d;
    if( a == c and b == d ) cerr << "ac\n";
    else { cerr << "wa\n"; break; }
    }
    return 0;
}