//배열 초기화 memset 사용법 익히기.  헤더파일은 cstring

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

void dfs(vector<int>*, bool*, int);
void bfs(vector<int>*, bool*, int, queue<int>&);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, v;
	cin >> n >> m >> v;
	vector<int> graph[1001];
	bool check[1001] = {false,};
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(graph, check, v);
	cout << '\n';
	memset(check, false, sizeof(check));
	queue<int> q;
	bfs(graph, check, v, q);
	return 0;
}

void dfs(vector<int>* graph, bool* check, int v) {
	if (check[v]) return;
	cout << v << ' ';
	check[v] = true;
	for (int i = 0; i < graph[v].size(); i++)
		dfs(graph, check, graph[v][i]);
}

void bfs(vector<int>* graph, bool* check, int v, queue<int>& q) {
	q.push(v);
	cout << v << ' ';
	check[v] = true;
	while (!q.empty()) {
		int vertax = q.front();
		q.pop();
		for (int i = 0; i < graph[vertax].size(); i++) {
			if (check[graph[vertax][i]]) continue;
			q.push(graph[vertax][i]);
			cout << graph[vertax][i] << ' ';
			check[graph[vertax][i]] = true;
		}
	}
}

