#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int[][50], bool[][50], queue<pair<int, int>>& q, int, int);

int dx[8] = { 0 ,  1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int w, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> answerList;

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		int map[50][50];
		bool check[50][50] = { false, };
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		int islandCnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!check[i][j] && map[i][j] == 1) {
					queue<pair<int, int>> q;
					bfs(map, check, q, i, j);
					islandCnt++;
				}
			}
		}
		answerList.push_back(islandCnt);
	}
	for (int i = 0; i < answerList.size(); i++)
		cout << answerList[i] << '\n';
	return 0;
}

void bfs(int map[][50], bool check[][50], queue<pair<int, int>>& q, int i, int j) {
	q.push(make_pair(i, j));
	check[i][j] = true;
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				int x = pos.first + dx[i]; int y = pos.second + dy[i];
				if (0 <= x && x < h && 0 <= y && y < w && !check[x][y] && map[x][y] == 1) {
					q.push(make_pair(x, y));
					check[x][y] = true;
				}
			}
		}
	}
}
