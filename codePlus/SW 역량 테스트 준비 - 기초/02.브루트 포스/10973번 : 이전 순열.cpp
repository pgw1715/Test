// prev_permutation 사용법 익히기

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		list.push_back(num);
	}

	if (prev_permutation(list.begin(), list.end())) {
		for (int i = 0; i < n; i++) {
			printf("%d ", list[i]);
		}
	}
	else {
		printf("%d\n", -1);
	}
	return 0;
}
