// 배열을 0부터 n-1까지가 아니라 1부터 n까지 쓰고싶은데 string[] 배열이라 1부터 n까지 쓰면 string의 0번째 idx가 쓰일 수 없음. 
// 그냥 0부터 n-1까지 쓰는게 속편함

#include <iostream>
#include <cstring>
#include <deque>
#include <string>

#define MAX_SIZE 101

using namespace std;

int dx[4] = { 0, 1, 0, -1};
int dy[4] = {-1, 0, 1,  0};
int m, n;

void bfs(string*, int[][MAX_SIZE]);

int main() {
	cin >> m >> n;
	string map[MAX_SIZE];
	int check[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	memset(check, -1, sizeof(check));

	bfs(map, check);
	cout << check[n-1][m-1] << '\n';
	return 0;
}

void bfs(string* map, int check[][MAX_SIZE]) {
	deque<pair<int,int>> q;
	q.push_front(make_pair(0, 0));
	check[0][0] = 0;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop_front();
		for (int i = 0; i < sizeof(dx) / sizeof(int); i++) {
			pair<int, int> next = make_pair(now.first + dx[i], now.second + dy[i]);
			if (0 <= next.first && next.first < n && 0 <= next.second && next.second < m && check[next.first][next.second] == -1) {
				if (map[next.first][next.second] == '0') {
					q.push_front(next);
					check[next.first][next.second] = check[now.first][now.second];
				}
				else {
					q.push_back(next);
					check[next.first][next.second] = check[now.first][now.second] + 1;
				}
			}
		}
	}
}

