#include <iostream>

using namespace std;

void makePermutation(int, int, int*, int, int);
void printPermutation(int*, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int permutation[8];
	makePermutation(n, m, permutation, 0, 0);
	return 0;
}

void makePermutation(int n, int m, int* permutation, int pick, int start) {
	if (pick == m) {
		printPermutation(permutation, m);
		return;
	}
	for (int i = start; i < n; i++) {
		permutation[pick] = i + 1;
		makePermutation(n, m, permutation, pick + 1, i);
	}
}

void printPermutation(int* permutation, int m) {
	for (int i = 0; i < m; i++)
		cout << permutation[i] << ' ';
	cout << '\n';
}
