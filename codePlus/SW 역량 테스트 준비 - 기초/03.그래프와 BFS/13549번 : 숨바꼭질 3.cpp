//bfs 함수 안의 if문 순서를 now+1 / now-1 / now*2 순서로 했었는데 그 코드는 오답이었음.
// if문의 순서가 바뀐다고 왜 오답코드가 되냐?  ->  check배열에 비용을 적는데 if문 now+1 / now-1 부터보면  now*2부터 보는 것 보다 비용이 더 커짐 

#include <iostream>
#include <deque>
#include <cstring>

#define MAX_SIZE 100001

using namespace std;

int bfs(int, int, int*);

int main() {
	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n';
		return 0;
	}
	int check[MAX_SIZE];
	memset(check, -1, sizeof(check));

	cout << bfs(n, k, check) << '\n';
	return 0;
}

int bfs(int n, int k, int* check) {
	deque<int> q;
	q.push_front(n);
	check[n] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop_front();
		if (now * 2 <= MAX_SIZE && check[now * 2] == -1) {
			if (now * 2 == k) return check[now];
			q.push_front(now * 2);
			check[now * 2] = check[now];
		}
		if (now - 1 >= 0 && check[now - 1] == -1) {
			if (now - 1 == k) return check[now] + 1;
			q.push_back(now - 1);
			check[now - 1] = check[now] + 1;
		}
		if (now + 1 <= MAX_SIZE && check[now + 1] == -1) {
			if (now + 1 == k) return check[now] + 1;
			q.push_back(now + 1);
			check[now + 1] = check[now] + 1;
		}
	}
}
