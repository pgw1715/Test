#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,m;

void bfs(string*, int[][100], queue<pair<int,int>>&);

int main(){
	string map[100];
	int check[100][100];
	memset(check, 0, sizeof(check));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>> map[i];
	}

	queue<pair<int,int>> q;
	bfs(map, check, q);

	cout<<check[n-1][m-1]<<'\n';
	return 0;
}

void bfs(string* map, int check[][100], queue<pair<int,int>>& q){
	q.push(make_pair(0,0));
	check[0][0] = 1;
	while(!q.empty()){
		pair<int,int> pos = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int x = pos.first + dx[i]; int y = pos.second + dy[i];
			if(0<=x && x<n && 0<=y && y<m && map[x][y] == '1' && check[x][y] == 0){
				q.push(make_pair(x,y));
				check[x][y] = check[pos.first][pos.second] + 1;
				if(check[m-1][n-1] != 0) return;
			}
		}
	}
}
