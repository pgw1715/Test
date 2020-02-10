#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermutation(int, vector<int>&, int*, bool*, int);
void printPermutation(int*, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> numList;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numList.push_back(num);
	}
	sort(numList.begin(), numList.end());

	int permutation[8];
	bool check[8] = { false, };
	makePermutation(m,numList,permutation, check,0);
	return 0;
}

void makePermutation(int m, vector<int>& numList, int* permutation, bool* check, int pick) {
	if (pick == m) {
		printPermutation(permutation, m);
		return;
	}
	for (int i = 0; i < numList.size(); i++) {
		if (check[i]) continue;
		permutation[pick] = numList[i];
		check[i] = true;
		makePermutation(m, numList, permutation, check, pick + 1);
		check[i] = false;
	}
}

void printPermutation(int* permutation, int m) {
	for (int i = 0; i < m; i++)
		cout << permutation[i] << ' ';
	cout << '\n';
}
