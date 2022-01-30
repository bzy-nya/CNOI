#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
#define db double
int n,m,a[N];
db calc(){
	int s=0;For(i,1,n){
		if(s>a[i]*(i-1));
		else s+=m;
	}return 1.0*s/n;
}
signed main(){
    freopen( "0.in", "r", stdin );
    freopen( "0.out", "w", stdout );
	n=read(),m=read();
	For(i,1,n)a[i]=read();sort(a+1,a+1+n);
	printf("%.2lf ",calc()),reverse(a+1,a+1+n);
	printf("%.2lf\n",calc());
	return 0;
}