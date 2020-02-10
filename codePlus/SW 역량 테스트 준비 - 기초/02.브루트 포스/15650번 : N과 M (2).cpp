#include <iostream>
#include <vector>

using namespace std;

void makePermutation(int, int, int, vector<int>&, int);
void printPermutation(vector<int>&, int);

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> permutation;
	makePermutation(0, n, m, permutation, 0);
	return 0;
}

void makePermutation(int idx, int n, int m, vector<int>& permutation, int pick) {
	if (pick == m) {
		printPermutation(permutation, m);
		return;
	}
	if (idx >= n)
		return;
	permutation.push_back(idx + 1);
	makePermutation(idx + 1, n, m, permutation, pick + 1);
	permutation.pop_back();
	makePermutation(idx + 1, n, m, permutation, pick);
}

void printPermutation(vector<int>& permutation, int m) {
	for (int i = 0; i < m; i++)
		cout << permutation[i] << ' ';
	cout << '\n';
}
