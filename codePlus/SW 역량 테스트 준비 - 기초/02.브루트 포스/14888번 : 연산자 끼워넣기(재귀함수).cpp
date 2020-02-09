//재귀함수 시작을 0번째 부터하는게 아니라 1부터하는게 중요.

include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void chooseCal(int, int, int, int, int, vector<int>&, vector<int>&, int);

int main() {
	vector<int> numList;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		numList.push_back(a);
	}
	int plusCnt, minusCnt, mulCnt, divCnt;
	scanf("%d %d %d %d", &plusCnt, &minusCnt, &mulCnt, &divCnt);
	
	vector<int> resultList;
	chooseCal(plusCnt, minusCnt, mulCnt, divCnt, 1, numList, resultList, numList[0]);

	auto ans = minmax_element(resultList.begin(), resultList.end());
	printf("%d\n%d\n", *ans.second, *ans.first);
	return 0;
}

void chooseCal(int plusCnt, int minusCnt, int mulCnt, int divCnt, int idx, vector<int>& numList, vector<int>& resultList, int sum) {
	if (idx == numList.size()) {
		resultList.push_back(sum);
		return;
	}
	if (idx >= numList.size())
		return;

	if (plusCnt > 0) chooseCal(plusCnt - 1, minusCnt, mulCnt, divCnt, idx + 1, numList, resultList, sum + numList[idx]);
	if (minusCnt > 0) chooseCal(plusCnt, minusCnt - 1, mulCnt, divCnt, idx + 1, numList, resultList, sum - numList[idx]);
	if (mulCnt > 0) chooseCal(plusCnt, minusCnt, mulCnt - 1, divCnt, idx + 1, numList, resultList, sum * numList[idx]);
	if (divCnt > 0) chooseCal(plusCnt, minusCnt, mulCnt, divCnt - 1, idx + 1, numList, resultList, sum / numList[idx]);
}
