#include<bits/stdc++.h>
using namespace std;

void print_div( long long x ) 
  { cout << "-" << x / 2 << ( (x & 1) ? ".5" : ".0" ); }

int main() {
    long long r1, r2, r3; cin >> r1 >> r2 >> r3;

    if( r3 >= r2 + r1 ) print_div( 2 * ( r3 * (r2 + r1) - r2 * r1 ) );
    else print_div( r1 * r1 + r2 * r2 + r3 * r3 );
}
