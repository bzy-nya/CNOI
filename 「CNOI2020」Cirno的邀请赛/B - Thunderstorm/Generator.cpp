#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1000;
int a, b, c;
int mod, low;

int rnd() { return (rand() << 10) ^ rand(); }

void gen_random() {
	cout << N << " " << M << " " << a << " " << b << " " << c << "\n";
	
	for( int i = 1; i <= N; i ++, putchar( '\n' ) ) for( int j = 1; j <= M; j ++ )
	  { cout << ( rnd() % mod ) + low << " "; }
}

void gen_power2() {
	cout << N << " " << M << " " << a << " " << b << " " << c << "\n";
	
	for( int i = 1; i <= N; i ++, putchar( '\n' ) ) for( int j = 1; j <= M; j ++ )
	  { cout << ( 1 << (rnd() % 24) ) - 1 << " "; }
}

void set_subtask1() { mod = 1; }
void set_subtask2() { mod = 2; low = 0; }
void set_subtask3() { a = b = c = rnd() % M + 1; }

int main() {
	freopen( "10.in", "w", stdout );
	srand( time(NULL) );
	
	mod = 998244353; low = 1;
	a = rnd() % M + 1;
	b = rnd() % M + 1;
	c = rnd() % M + 1;
	
	//set_subtask1();
	//set_subtask2();
	//set_subtask3();
	
	//gen_random();
	gen_power2();
	
	return 0;
} 
