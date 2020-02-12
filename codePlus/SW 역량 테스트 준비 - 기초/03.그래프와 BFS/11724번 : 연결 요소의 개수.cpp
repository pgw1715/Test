#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>*, bool*, int);

int main() {
	vector<int> graph[1001];
	bool check[1001] = { false, };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(graph, check, i);
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}

void dfs(vector<int>* graph, bool* check, int v) {
	if (check[v]) return;
	check[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		dfs(graph, check, graph[v][i]);
	}
}
