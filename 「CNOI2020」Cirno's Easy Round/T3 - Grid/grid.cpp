#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL; 

int main() {
	ULL n; cin >> n;
	
	cout << n << "\n";
	
	for( ULL i = 1; i <= n; i ++ ) {
		ULL ans =0;
		for( ULL j = 1; j <= n; j ++ ) {
			ans |= 1ull << ( i + j % n );
			cout << ans << " ";
		}
		cout << "\n";
	}
	
	return 0;
} 
