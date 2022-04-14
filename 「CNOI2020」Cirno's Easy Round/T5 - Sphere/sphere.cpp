#include<bits/stdc++.h>
using namespace std;

typedef __int128 I128; 

I128 e = 1;

int l[100005];
int r[100005]; 

vector<int> S, P;

ostream& operator <<( ostream& A, I128 B){
    if(B == 0) return A;
    return A << (B / 10) << (int)(B % 10);
}

int main() {
	int n; cin >> n; S.clear(); P.clear();
	
	for( int i = 1; i <= n; i ++ ) cin >> l[i] >> r[i];
	for( int i = 1; i <= n; i ++ ) S.push_back( l[i] ), S.push_back( r[i] );
	
	sort( S.begin(), S.end() );
	
	int std = S[n];
	I128 ans = 0;
	
	for( int i = 1; i <= n; i ++ ) {
		if( r[i] < std ) P.push_back( r[i] ); else
		if( l[i] > std ) P.push_back( l[i] ); else
		if( r[i] >= std and l[i] <= std ) P.push_back( std );
	}
	
	sort( P.begin(), P.end() ); 
	
	for( int i = 0; i < n; i ++ ) ans += e * P[i] * (e * 2 * i - n + e);
	
	cout << ans * 2;
	
	return 0;
}
