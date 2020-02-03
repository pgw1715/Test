// 모든 순열 구하기는 do while 문을 사용!
//   why? while 문을 사용해버리면 조건검사를하면서 다음순열로 넘어간 다음 반복문안으로 들어가기 때문.
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		list.push_back(i);
	}

	do {
		for (int i = 0; i < n; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
	} while (next_permutation(list.begin(), list.end()));
	
	return 0;
}
