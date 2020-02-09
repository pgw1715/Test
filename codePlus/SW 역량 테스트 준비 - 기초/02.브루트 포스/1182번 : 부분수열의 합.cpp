//공집합 case 제거 ㅅㅂ;;;

#include <stdio.h>
#include <vector>

using namespace std;

int getAnswer(vector<int>&, int, int, int);

int main() {
	vector<int> numList;
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		numList.push_back(num);
	}
	int answer = getAnswer(numList, 0, s, 0);
	if (s == 0) printf("%d\n", answer - 1);
	else printf("%d\n", answer);
	return 0;
}

int getAnswer(vector<int>& numList, int idx, int s, int sum) {
	if (idx == numList.size() && s == sum)
		return 1;
	if (idx >= numList.size())
		return 0;
	return getAnswer(numList, idx + 1, s, sum + numList[idx]) + getAnswer(numList, idx + 1, s, sum);
}
