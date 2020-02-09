// 처음에 max = 0, min = 2147483647 로 두고 
// if(sum>max) max=sum 으로 했으나 오답.   max가 음수가 될 수도 있기 때문!
// auto 의 사용법 익히기
//	auto ans = minmax_element(result.begin(), result.end());
//	printf("%d\n%d\n", *ans.second, *ans.first);  -> second 가 최대값 , first가 최소값


#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numList;
vector<int> calList;

int main() {
	int numCnt;
	scanf("%d", &numCnt);
	for (int i = 0; i < numCnt; i++) {
		int n;
		scanf("%d", &n);
		numList.push_back(n);
	}
	for (int i = 1; i <= 4; i++) {
		int cal;
		scanf("%d", &cal);
		for (int j = 0; j < cal; j++) {
			calList.push_back(i);
		}
	}

	vector<int> result;
	do {
		int sum = numList[0];
		for (int i = 1; i < numList.size(); i++) {
			switch (calList[i - 1]) {
			case 1:
				sum += numList[i];
				break;
			case 2:
				sum -= numList[i];
				break;
			case 3:
				sum *= numList[i];
				break;
			case 4:
				sum /= numList[i];
				break;
			}
		}
		result.push_back(sum);
	} while (next_permutation(calList.begin(), calList.end()));

	auto ans = minmax_element(result.begin(), result.end());

	printf("%d\n%d\n", *ans.second, *ans.first);
	return 0;
}
