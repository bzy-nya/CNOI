#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n, m;
long long dis[3][N][N];
int d[N][N];
bool sel[N][N];


const int dx[4] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

struct poi {
	int x, y;
	ll dis;
	poi(int _x, int _y, ll _d): x(_x), y(_y), dis(_d) {}
	bool operator <( const poi &F ) const {
		return dis > F.dis;
	}
};
priority_queue<poi> q;

void Dij(int k, int sx, int sy) {
	while (!q.empty())
		q.pop();
	memset(sel, 0, sizeof(sel));
	memset(dis[k], 23, sizeof(dis[k]));
	dis[k][sx][sy] = d[sx][sy];
	q.push(poi(sx, sy, dis[k][sx][sy]));
	while (!q.empty()) {
		int ux = q.top().x, uy = q.top().y;
		ll disu = q.top().dis;
		q.pop();
		if (sel[ux][uy])
			continue;
		sel[ux][uy] = 1;
		for (int i = 0; i < 4; i++) {
			int vx = ux + dx[i], vy = uy + dy[i];
			if (vx > 0 && vy > 0 && vx <= n && vy <= m)
				;
			else
				continue;
			if (sel[vx][vy] || disu + d[vx][vy] >= dis[k][vx][vy])
				continue;
			dis[k][vx][vy] = disu + d[vx][vy];
			q.push(poi(vx, vy, dis[k][vx][vy]));
		}
	}
}

int main() {
	int a, b, c;
	cin >> n >> m >> a >> b >> c;
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			scanf("%d", &d[i][j]);
	Dij(0, n, a);
	Dij(1, 1, b);
	Dij(2, 1, c);
	long long ans = 1LL << 62;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - 2 * d[i][j]);
		}
	}
//	for (int i=1;i<=n;i++) {for (int j=1;j<=m;j++) printf("%d ",dis[0][i][j]);putchar('\n');}putchar('\n');
//	for (int i=1;i<=n;i++) {for (int j=1;j<=m;j++) printf("%d ",dis[1][i][j]);putchar('\n');}putchar('\n');
//	for (int i=1;i<=n;i++) {for (int j=1;j<=m;j++) printf("%d ",dis[2][i][j]);putchar('\n');}putchar('\n');
	cout << ans << endl;
}