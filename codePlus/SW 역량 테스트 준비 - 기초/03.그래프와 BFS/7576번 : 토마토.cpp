#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;
int map[1001][1001];
int check[1001][1001];
void bfs(queue<pair<int, int>>&);
int getAnswer();

int main() {
	cin >> n >> m;
	queue<pair<int, int>> q;
	memset(check, -1, sizeof(check));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 0;
			}
			if (map[i][j] == -1)
				check[i][j] = -5;
		}
	}

	bfs(q);
	cout << getAnswer() << '\n';
	return 0;
}

void bfs(queue<pair<int, int>>& q) {
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		for (int i = 0; i < sizeof(dx) / sizeof(int); i++) {
			int x = pos.first + dx[i]; int y = pos.second + dy[i];
			if (0 < x && x <= m && 0 < y && y <= n && map[x][y] == 0 && check[x][y] == -1) {
				q.push(make_pair(x, y));
				check[x][y] = check[pos.first][pos.second] + 1;
			}
		}

	}
}

int getAnswer() {
	int max = -1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == -1) return -1;
			if (check[i][j] > max) max = check[i][j];
		}
	}
	return max;
}
