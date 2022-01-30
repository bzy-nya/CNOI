#include<bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];

int main() {
	int n; cin >> n;
	for( int i = 1; i <= n; i ++ ) cin >> a[i];
	for( int i = 1; i <= n; i ++ ) cin >> b[i];
	int ans = 0;
	for( int i = 1; i <= n; i ++ ) ans += min( a[i], b[i] );
	cout << ans;
	return 0;
}
