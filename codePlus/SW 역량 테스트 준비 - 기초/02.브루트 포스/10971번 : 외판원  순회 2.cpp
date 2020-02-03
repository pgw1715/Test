//도시 개수가 10 이하이므로 브루프포스 가능!
// 최소비용을 구하는 것이므로 minCost를 int 최대값인 2147483647 로 초기화.

#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_SIZE 10

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
vector<int> list;

int main() {
	int cityCnt;
	scanf("%d", &cityCnt);
	for (int i = 0; i < cityCnt; i++)
		list.push_back(i);

	for (int i = 0; i < cityCnt; i++) {
		for (int j = 0; j < cityCnt; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int minCost = 2147483647;
	do {
		int tmp = 0;
		bool isPass = true;
		
		for (int i = 0; i + 1 < cityCnt; i++) {
			if (map[list[i]][list[i + 1]] != 0)
				tmp += map[list[i]][list[i + 1]];
			else
				isPass = false;
		}

		if (isPass && map[list[cityCnt-1]][0] != 0) {
			tmp += map[list[cityCnt - 1]][0];
			if (minCost > tmp) minCost = tmp;
		}

	} while (next_permutation(list.begin() + 1, list.end()));
    
	printf("%d\n", minCost);
	return 0;
}
