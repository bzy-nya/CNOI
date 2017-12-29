#include<bits/stdc++.h>
using namespace std;

int N = 20000;
int M = 20000;

void gen_random();
void gen_chain ();
void gen_sweep ();

int main() {
	freopen( "4.in", "w", stdout );
	
	srand( time(NULL) );
	
	cout << N << " " << M << "\n";
	
	gen_random();
	
	return 0; 
} 

void gen_random() {
	int f = 0;
	for( int i = 1; i <= N; i ++ ) {
		int r = rand() % 4;
		if( !r and f ) cout << "erase\n", f --;
		else cout << "add " << rand() % ( M - 1 ) + 1 << " " << rand() % M << "\n", f ++;
	}
}

void gen_chain() {
	for( int i = 1; i <= N; i ++ ) {
		cout << "add " << rand() % (int)sqrt(M) + 1 << " " << rand() % M << "\n";
	}
}

void gen_sweep() {
	int f = 0;
	for( int i = 1; i <= N; i ++ ) {
		int r = rand() % 25;
		if( !r and f ) cout << "erase\n", f --;
		else cout << "add " << rand() % M << " " << rand() % M << "\n", f ++;
	}
}
