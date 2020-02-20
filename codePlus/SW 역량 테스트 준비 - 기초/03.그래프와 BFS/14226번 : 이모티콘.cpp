// check 배열을 main안에서 선언하면 오류가남.. 크기가 너무 커서 그런듯

#include <iostream>
#include <queue>
#include <cstring>

#define MAX_SIZE 2001

using namespace std;

int check[MAX_SIZE][MAX_SIZE];

int bfs(int);

int main(){
	int s;
	cin>>s;
	
	memset(check,0,sizeof(check));
	cout<<bfs(s)<<'\n';

	return 0;
}

int bfs(int s){
	queue<pair<int,int>> q;
	q.push(make_pair(1,0));
	check[1][0] = 0;
	while(!q.empty()){
		pair<int,int> pos = q.front();
		q.pop();
		if(pos.first<MAX_SIZE && check[pos.first][pos.first] == 0){ //복사
			q.push(make_pair(pos.first, pos.first));
			check[pos.first][pos.first] = check[pos.first][pos.second]+1;
		}
		if(pos.first + pos.second < MAX_SIZE && check[pos.first+pos.second][pos.second] == 0){//붙여넣기
			if(pos.first+pos.second == s) return check[pos.first][pos.second]+1;
			q.push(make_pair(pos.first+pos.second, pos.second));
			check[pos.first+pos.second][pos.second] = check[pos.first][pos.second]+1;
		}
		if(pos.first-1 >= 0 && check[pos.first-1][pos.second] == 0){
			if(pos.first-1 == s) return check[pos.first][pos.second]+1;
			q.push(make_pair(pos.first-1, pos.second));
			check[pos.first-1][pos.second] = check[pos.first][pos.second]+1;
		}
	}
}
