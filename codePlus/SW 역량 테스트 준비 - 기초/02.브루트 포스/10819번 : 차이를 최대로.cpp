// 문제풀기전 경우의 수가 몇개인지 계산.  천만 이하면 브루프포스 이용
// 항상 염두할 것

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;

int getAnswer();

int main() {
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		int num;
		scanf("%d", &num);
		list.push_back(num);
	}

	sort(list.begin(), list.end());
	int max = 0;
	do {
		int tmp = getAnswer();
		if (max < tmp) max = tmp;

	} while (next_permutation(list.begin(), list.end()));

	printf("%d\n", max);

	return 0;
}

int getAnswer() {
	int sum = 0;
	for (int i = 0; i + 1 < list.size(); i++) {
		int tmp = list[i] - list[i + 1];
		if (tmp > 0)
			sum += tmp;
		else
			sum += tmp * (-1);
	}
	return sum;
}
