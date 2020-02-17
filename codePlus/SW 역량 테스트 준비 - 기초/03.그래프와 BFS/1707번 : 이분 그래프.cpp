// 개씨발 쉬울거같은데 존나 어렵네 시발 개빡친다 이거때문에 시간을 얼마나 날린지 모르겠다 씨빨;ㅣㅏㅂㅁㅇㄴ로ㅓㅑㅣ휴;ㄹㄴㅁ;ㅣㅑㅐㅗㄹ되ㅓ;ㅔㅑㅐㅁㅈㄷㅂㄱ

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>*, int*, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	while (k--) {
		int v, e;
		cin >> v >> e;
		vector<int> graph[20001];
		int color[20001] = { 0, };
		for (int i = 1; i <= e; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		bool isOk = true;                // isOk = false 로 두고 밑에 dfs 가 참이면  isOk = true 로 바꿔주는 코드를 처음에 했지만 오답.
                                     // 반복문 돌면서 앞에꺼 다 false이다가 마지막 한번만 참이면 true로 바꿔주기때문에 오답임.
		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				if (dfs(graph, color, i, 1) == false)
					isOk = false;
			}
		}
		if (isOk) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}

bool dfs(vector<int>* graph, int* color, int v, int c) {
	color[v] = c;
	for (int i = 0; i < graph[v].size(); i++) {
		if (color[graph[v][i]] == 0) {
			if (dfs(graph, color, graph[v][i], 3 - c) == false)
				return false;
		}
		else if (color[graph[v][i]] == c)
			return false;
	}
	return true;
}
