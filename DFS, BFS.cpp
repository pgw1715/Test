#include <iostream>
#include <vector>

#include <queue>

#define vertex	7
#define edge	9
using namespace std;

void setgraph();
void dfs(int);
void bfs(int);

vector<int> graph[vertex + 1];
int isVisit[vertex+1];

queue<int> q;

int main() {
	setgraph();

	//dfs(1);
	bfs(1);

	return 0;
}

void setgraph(){
	graph[1].push_back(2);
	graph[1].push_back(3);

	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[2].push_back(4);
	graph[2].push_back(5);

	graph[3].push_back(1);
	graph[3].push_back(2);
	graph[3].push_back(6);
	graph[3].push_back(7);

	graph[4].push_back(2);
	graph[4].push_back(5);

	graph[5].push_back(2);
	graph[5].push_back(4);

	graph[6].push_back(3);
	graph[6].push_back(7);

	graph[7].push_back(3);
	graph[7].push_back(6);
}

void dfs(int v) {
	if (isVisit[v] == 1)
		return;
	isVisit[v] = 1;
	cout << v << ' ';

	for (int i = 0; i < graph[v].size(); i++) {
		int y = graph[v][i];
		dfs(y);
	}
	
}

void bfs(int v) {
	q.push(v);
	isVisit[v] = 1;
	cout << v << ' ';

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (isVisit[y] != 1) {
				q.push(y);
				isVisit[y] = 1;
				cout << y << ' ';
			}			
		}
	}

}