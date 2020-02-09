#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void makeConList(int, vector<pair<int, int>>&, int, vector<int>&);

int main() {
	vector<pair<int, int>> conList;
	vector<int> costList;
	int n, t, p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t, &p);
		conList.push_back(make_pair(t, p));
	}

	makeConList(0, conList, 0, costList);
	auto ans = minmax_element(costList.begin(), costList.end());
	printf("%d\n", *ans.second);
	return 0;
}

void makeConList(int idx, vector<pair<int, int>>& conList, int cost, vector<int>& costList) {
	if (idx <= conList.size())
		costList.push_back(cost);
	if (idx >= conList.size())
		return;
	makeConList(idx + conList[idx].first, conList, cost + conList[idx].second, costList);
	makeConList(idx + 1, conList, cost, costList);
}
