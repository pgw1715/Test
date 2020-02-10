#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermutation(int, int, vector<int>&, int*, int);
void printPermutation(int*, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int>numList;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numList.push_back(num);
	}
	sort(numList.begin(), numList.end());

	int permutation[7];
	makePermutation(n,m,numList,permutation,0);
	return 0;
}

void makePermutation(int n, int m, vector<int>& numList, int* permutation, int pick) {
	if (pick == m) {
		printPermutation(permutation, m);
		return;
	}
	for (int i = 0; i < n; i++) {
		permutation[pick] = numList[i];
		makePermutation(n, m, numList, permutation, pick + 1);
	}
}

void printPermutation(int* permutation, int m) {
	for (int i = 0; i < m; i++)
		cout << permutation[i] << ' ';
	cout << '\n';
}
