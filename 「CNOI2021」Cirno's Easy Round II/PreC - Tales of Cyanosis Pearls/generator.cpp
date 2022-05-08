#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

int c[N][N];

int main() {
	freopen( "10.in", "w", stdout );
	srand( time(NULL) ); 
	for( int i = 0; i < N; i ++ ) for( int j = 0; j < N; j ++ )
	  { c[i][j] = i; }
	for( int i = 0; i < N * N; i ++ ) {
		int x = rand() % N;
		int y = rand() % N;
		int u = rand() % N;
		int v = rand() % N;
		swap( c[x][y], c[u][v] );
	}
	for( int i = 0; i < N; i ++, putchar('\n') ) 
	  { for( int j = 0; j < N; j ++ ) cout << c[i][j] + 1 << " "; }
}
