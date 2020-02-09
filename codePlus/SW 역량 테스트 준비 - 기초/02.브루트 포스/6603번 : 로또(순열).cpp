// 입력을 먼저 다하고 출력이 나오는 건줄알았는데
// 입력1 출력1 , 입력2 출력2  로 나와도 정답처리가 됨;

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;
vector<int> check;

void printPermutation();

int main() {
	while (true) {
		int k;
		scanf("%d", &k);
		if (k == 0)
			return 0;

		list.clear();
		check.clear();
		for (int i = 0; i < k; i++) {
			int n;
			scanf("%d", &n);
			list.push_back(n);
			if (i < 6) check.push_back(1);
			else check.push_back(2);
		}

		printPermutation();
	}
	return 0;
}

void printPermutation() {
	do {
		for (int i = 0; i < list.size(); i++) {
			if (check[i] == 1)
				printf("%d ", list[i]);
		}
		printf("\n");
	} while (next_permutation(check.begin(), check.end()));
	printf("\n");
}

//선택된 것 : 1 선택되지 않은 것 : 2 로 두고 푸는게 keyPoint
