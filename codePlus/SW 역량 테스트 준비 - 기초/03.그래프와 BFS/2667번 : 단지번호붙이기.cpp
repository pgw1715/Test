#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int bfs(string*, bool[][25], int, int, queue<pair<int,int>>&);

int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	cin >> n;
	string map[25];
	bool check[25][25] = { false, };

	for (int i = 0; i < n; i++) {
			cin >> map[i];
	}

	vector<int> answerList;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && map[i][j] == '1') {
				queue<pair<int, int>> q;
				answerList.push_back(bfs(map, check, i, j, q));
			}
		}
	}
	sort(answerList.begin(), answerList.end());

	cout << answerList.size() << '\n';
	for (int i = 0; i < answerList.size(); i++)
		cout << answerList[i] << '\n';
	return 0;
}

int bfs(string map[25], bool check[][25], int i, int j, queue<pair<int,int>>& q) {
	int size = 0;
	q.push(make_pair(i, j));
	check[i][j] = true;
	size++;
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = pos.first + dx[i]; int y = pos.second + dy[i];
			if (x < n && x >= 0 && y < n && y >= 0 && !check[x][y] && map[x][y] == '1') {
				q.push(make_pair(x, y));
				check[x][y] = true;
				size++;
			}
		}
	}
	return size;
}
