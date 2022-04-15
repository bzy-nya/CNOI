#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

long long f_pow(long long A,long long B){
    long long ans = 1;
    while( B ){
        if( B & 1 )( ans *= A ) %= mod;
        ( A *= A ) %= mod;
        B >>= 1;
    }
    return ans;
}

long long ns(long long A){
    return f_pow( A, mod - 2);
}

int main(){
    long long n; cin >> n; n %= mod;
    if( n == 0 )return cout << ns(2),0;
    cout << ( ns(2) * ( 1 - 3ll  * ns(n) % mod * ns(n + 2) % mod ) % mod + mod ) % mod;
    return 0;
}

