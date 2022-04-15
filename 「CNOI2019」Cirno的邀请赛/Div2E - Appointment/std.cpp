#include<bits/stdc++.h>
using namespace std;

bitset<1 << 25> ext;

const int mod = 998244353;

template<typename T,int height,int width>
struct matrix{
    T num[height][width];
    
    T* operator [](int Line)
      { return num[Line]; }
    
    matrix() {  
        for( int i = 0;i < height; ++ i )
            for( int j = 0;j < width;j ++ )
              { num[i][j] = T(); }
    }
    
    template<int widthN>
    matrix<T,height,widthN> operator *
        ( matrix<T,width,widthN> From ) {
            matrix<T,height,widthN> rt;
            for(int i = 0;i < height;i ++)
                for(int j = 0;j < widthN;j ++)
                    for(int k = 0;k < width;k ++)
                      { rt[i][j] += 1ll * num[i][k] * From.num[k][j] % mod; }
            for(int i = 0;i < height;i ++)
                for(int j = 0;j < widthN;j ++)
                    rt[i][j] %= mod;
            return rt;
        }
};

int inv(int x) {
    int r = 1;
    for( int s = mod - 2; s; s >>= 1, x = 1ll * x * x % mod )
      { if( s & 1 ) r = 1ll * r * x % mod; }
    return r;
}

typedef matrix<long long,220,220> M;
typedef matrix<long long,220,1> V;

vector<int> tp[220];
int cnt = -1;

M ele;
V ans;

int main(){
    long long L; int n; cin >> L >> n; L --;
    int len = (1 << n);
    for(int i = 0;i < len;i ++) {
        int x = i;
        if( (x & 1) and (x & ( 1 << (n - 1) ) ) ) continue;
        int flag = 0;
        for( ;x; x >>= 1 ) if( (x & 3) == 3 ) flag = true;
        if( flag ) continue;
        if( ext[i] ) continue;
        cnt ++;
        x = i;
        for(int i = 1;i <= n * 2;i ++) {
            if( !ext[x] ) tp[cnt].push_back(x);
            ext[x] = true;
            x = (x >> 1) | ( (x & 1) << (n - 1) );
        }
    }
    for(int i = 0;i <= cnt;i ++) for(int j = 0;j <= cnt;j ++) {
        int pnt = 0;
        for( auto A : tp[i] ) for( auto B : tp[j] ) if( !(A & B) ) pnt ++;
        ele[j][i] = 1ll * pnt * inv( tp[i].size() ) % mod;
    }
    for(int i = 0;i <= cnt;i ++) ans[i][0] = tp[i].size();
    for( ;L; L >>= 1, ele = ele * ele )
      { if( L & 1ll ) ans = ele * ans; }
    int all = 0;
    for(int i = 0;i <= cnt;i ++) ( all += ans[i][0] ) %= mod;
    cout << all;
    return 0;
}
