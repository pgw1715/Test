//물이 벽에 같혀있어서 맵 전체에 퍼지지 않는 경우도 생각해줘야된다.
//   -> (gosumCheck[x][y]+1 < waterCheck[nx][ny] || waterCheck[nx][ny] == -1)
//                                                  ------------------------
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <tuple>

using namespace std;

char map[51][51];
int waterCheck[51][51];
int gosumCheck[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void waterBFS(int, int, queue<tuple<int,int>>&);
void gosumBFS(int, int, queue<tuple<int, int>>&);

int main() {
	int r, c;
	cin >> r >> c;
	getchar();
	int biberX, biberY;
	queue<tuple<int, int>> waterQ;
	queue<tuple<int, int>> gosumQ;
	memset(waterCheck, -1, sizeof(waterCheck));
	memset(gosumCheck, -1, sizeof(gosumCheck));
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%1c", &map[i][j]);
			if (map[i][j] == '*') {
				waterQ.push(make_tuple(i, j));
				waterCheck[i][j] = 0;
			}
			if (map[i][j] == 'D') {
				biberX = i; biberY = j;

			}
			if (map[i][j] == 'S') {
				gosumQ.push(make_tuple(i, j));
				gosumCheck[i][j] = 0;
			}
		}
		getchar();
	}
	waterBFS(r, c, waterQ);
	gosumBFS(r, c, gosumQ);

	if (gosumCheck[biberX][biberY] == -1)
		cout << "KAKTUS" << '\n';
	else
		cout << gosumCheck[biberX][biberY] << '\n';
	return 0;
}

void waterBFS(int r, int c, queue<tuple<int,int>>& waterQ) {
	while (!waterQ.empty()) {
		int x, y;
		tie(x, y) = waterQ.front();
		waterQ.pop();
		for (int i = 0; i < sizeof(dx) / sizeof(int); i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0<nx && nx<=r && 0<ny && ny<=c && (map[nx][ny] == '.' || map[nx][ny] == 'S') && waterCheck[nx][ny] == -1) {
				waterQ.push(make_tuple(nx, ny));
				waterCheck[nx][ny] = waterCheck[x][y] + 1;
			}
		}
	}
}

void gosumBFS(int r, int c, queue<tuple<int, int>>& gosumQ) {
	while (!gosumQ.empty()) {
		int x, y;
		tie(x, y) = gosumQ.front();
		gosumQ.pop();
		for (int i = 0; i < sizeof(dx) / sizeof(int); i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 < nx && nx <= r && 0 < ny && ny <= c && map[nx][ny] == '.' && (gosumCheck[x][y]+1 < waterCheck[nx][ny] || waterCheck[nx][ny] == -1) && gosumCheck[nx][ny] == -1) {
				gosumQ.push(make_tuple(nx, ny));
				gosumCheck[nx][ny] = gosumCheck[x][y] + 1;
			}
			if (0 < nx && nx <= r && 0 < ny && ny <= c && map[nx][ny] == 'D') {
				gosumCheck[nx][ny] = gosumCheck[x][y] + 1;
				return;
			}
		}
	}
}
