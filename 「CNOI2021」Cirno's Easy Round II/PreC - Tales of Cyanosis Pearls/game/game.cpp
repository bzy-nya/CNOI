#include<bits/stdc++.h>
using namespace std;

const int n = 5;

int mat[n][n]; 

int step = 0;
int left = n * n;

void printMatrix() {
	for( int i = 0; i < n; i ++, putchar( '\n' ) ) for( int j = 0; j < n; j ++ ) cout << mat[i][j] << " ";
}

int main() {
	srand( time(NULL) );
	
	for( int i = 0; i < n; i ++ ) for( int j = 0; j < n; j ++ )
	  { mat[i][j] = i + 1; }

	for( int i = 0; i < n * n; i ++ ) {
		int x = rand() % n;
		int y = rand() % n;
		int u = rand() % n;
		int v = rand() % n;
		
		swap( mat[x][y], mat[u][v] );
	}
	printMatrix();
	
	while( ::left > 0 ) {
		int a, b; cin >> a >> b;
		
		bool flag = false; 
		
		if( a <= 0 or b > n or a > b ) flag = true;
		for( int i = a; i < b; i ++ ) if( mat[n - 1][i] ^ mat[n - 1][i - 1] ) flag = true;
		
		if( flag ) { printf( "Illegal operation!\n" ); continue; }
		
		step ++; ::left -= b - a + 1;
		
		for( int i = n - 1; i >= 0; i -- ) for( int j = a - 1; j < b; j ++ ) mat[i][j] = mat[i - 1][j];
		for( int i = a - 1; i < b; i ++ ) mat[0][i] = 0;
		
		printMatrix();
	}
	
	printf( "Total step: %d", step );
	return 0;
} 
