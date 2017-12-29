#include<bits/stdc++.h>
using namespace std;

int MP[256];

int main() {
    char c; int ans = 0;
    
    while( c = getchar() ) 
      { if( c > 'z' or c < 'a' ) break;
        ans = max( ans , ++ MP[c] ); }
        
    cout << ans;
    return 0;
}
