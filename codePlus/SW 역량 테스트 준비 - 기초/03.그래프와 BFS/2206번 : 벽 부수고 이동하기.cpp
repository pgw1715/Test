//진짜 오래걸림 짜증남.
// map입력을 공백없이 받으면 string으로 받지말고 scanf("%1d")를 이용하자
//짜증남존나씨발

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <tuple>

using namespace std;

int map[1001][1001];
int check[1001][1001][2];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void bfs(int, int);

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	memset(check, 0, sizeof(check));
	bfs(n, m);

	if (check[n][m][0] != 0 && check[n][m][1] != 0)
		cout << min(check[n][m][0], check[n][m][1]) << '\n';
	else if (check[n][m][0] != 0)
		cout << check[n][m][0] << '\n';
	else if (check[n][m][1] != 0)
		cout << check[n][m][1] << '\n';
	else
		cout << -1 << '\n';

	return 0;
}

void bfs(int n, int m) {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 1, 0));
	check[1][1][0] = 1;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int i = 0; i < sizeof(dx) / sizeof(int); i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 >= nx || nx > n || 0 >= ny || ny > m) continue;
			if (map[nx][ny] == 0 && check[nx][ny][z] == 0) {
				q.push(make_tuple(nx, ny, z));
				check[nx][ny][z] = check[x][y][z] + 1;
			}
			if (map[nx][ny] == 1 && check[nx][ny][1] == 0 && z == 0) {
				q.push(make_tuple(nx, ny, 1));
				check[nx][ny][1] = check[x][y][z] + 1;
			}
		}
	}
}
