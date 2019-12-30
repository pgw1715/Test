#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int passCnt[20] = { 0 };

void printResult(int);
int getPassCnt(int);
bool compare(pair<int, int>, pair<int, int>);

int main() {
	int testcaseCnt;
	cin >> testcaseCnt;

	for (int i = 0; i < testcaseCnt; i++) {
		int pairCnt;
		cin >> pairCnt;
		for (int j = 0; j < pairCnt; j++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end(), compare);
		passCnt[i] = getPassCnt(pairCnt);
		v.clear();
	}

	printResult(testcaseCnt);
}

/* 처음에 푼 시간초과.. 시간복잡도 미침;;  법칙을 알았다고해서 무작정 코드짜지말고. 
                                        시간복잡도가 n제곱 이상이면 더 간단하게 풀 수 있는 방법 생각하기 
int getPassCnt(int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool isPass = true;
		int std = v[i].second;
		for (int j = i - 1; j >= 0; j--) {
			if (std > v[j].second) {
				isPass = false;
				break;
			}
		}
		if (isPass)
			cnt++;
	}
	return cnt;
}
*/

int getPassCnt(int n) {
	if (n == 0)
		return 0;

	int cnt = 1;
	int min = v[0].second;
	for (int i = 1; i < n; i++) {
		if (min > v[i].second) {
			cnt++;
			min = v[i].second;
		}
	}
	return cnt;
}

void printResult(int n) {
	for (int i = 0; i < n; i++)
		cout << passCnt[i] << "\n";
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first)
		return false;
	else
		return true;
}
