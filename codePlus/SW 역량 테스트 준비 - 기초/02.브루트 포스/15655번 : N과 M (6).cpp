#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermutation(vector<int>&, int, int, vector<int>&, int, int);
void printPermutation(vector<int>&);

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

	vector<int> permutation;
	makePermutation(numList, n, m, permutation, 0, 0);
	return 0;
}

void makePermutation(vector<int>& numList, int n, int m, vector<int>& permutation, int idx, int pick) {
	if (pick == m) {
		printPermutation(permutation);
		return;
	}
	if (idx >= n)
		return;
	permutation.push_back(numList[idx]);
	makePermutation(numList, n, m, permutation, idx + 1, pick + 1);
	permutation.pop_back();
	makePermutation(numList, n, m, permutation, idx + 1, pick);
}

void printPermutation(vector<int>& permutation) {
	for (int i = 0; i < permutation.size(); i++)
		cout << permutation[i] << ' ';
	cout << '\n';
}
