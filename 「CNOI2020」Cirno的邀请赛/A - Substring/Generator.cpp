#include<bits/stdc++.h>
using namespace std;

int N;

void gen_random() {
	while( N -- ) {
		char c = rand() % 26 + 'a';
		cout << c;
	}
}

void gen_constructive() {
	while( N -- ) {
		char c = rand() % 2 + 'a';
		cout << c;
	}
}

int main() { 
	srand( time(NULL) );
	
	freopen( "6.in", "w", stdout );
	
	N = 10000000;
	
	//gen_random();
	gen_constructive();
	return 0;
}
