#include<bits/stdc++.h>
using namespace std;

const int N = 1e9;

int r() { return (rand() << 22) ^ (rand() << 11) ^ rand(); } 
int rd( int x ) { return abs( r() ) % x + 1; }
 
int main() {
	srand( time(NULL) );
	
	freopen( "9.in", "w", stdout );
	
	cout << rd(N) << " " << rd(N) << " " << rd(N); 
} 
