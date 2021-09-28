#include<bits/stdc++.h>
using namespace std;

int N = 1000;
int K = 300;
int limit = 3;

int main() {
	srand( time(NULL) );
	freopen( "data15.in", "w", stdout );
	
	cout << N << " " << K << "\n";
	
	for( int i = 1; i <= N; i ++ )
	  { cout << rand() % limit << " "; } 
}
