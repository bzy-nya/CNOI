#include<bits/stdc++.h>
using namespace std;

int N, M;

void gen_subtask1() 
  { cout << N << " " << N << "\n"; 
    for( int i = 1; i <= N; i ++ ) cout << i << " " << i << "\n"; }

void gen_subtask2() 
  { cout << N << " " << N << "\n"; 
	cout << 1 << " " << 1 << "\n";
    for( int i = 2; i <= N; i ++ ) cout << i << " " << i - 1 << "\n"; }

void gen_subtask3() 
  { cout << N << " " << N << "\n"; 
    for( int i = 1; i <= N; i ++ ) cout << i << " " << 1 << "\n"; }

void gen_random() {
	cout << N << " " << M << "\n";
	for( int i = 1; i <= M; i ++ ) {
		int x = ( rand() ^ ( rand() << 10 ) ) % N + 1; 
		int y = ( rand() ^ ( rand() << 10 ) ) % N + 1;
		if( x < y ) swap( x, y );
		cout << x << " " << y << "\n";
	}
} 

int main() { 
	freopen( "15.in", "w", stdout );
	srand( time(NULL) );
	
	N = 1000000; M = 1000000;
	
	gen_random();
	return 0;
}
