#include <iostream>

using namespace std;

void makePermutation(int, int, int*, int);
void printPermutation(int, int*);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int permutation[7];
	makePermutation(n, m, permutation, 0);
	return 0;
}

void makePermutation(int n, int m, int* permutation, int pick) {
	if (pick == m) {
		printPermutation(m, permutation);
		return;
	}
	for (int i = 0; i < n; i++) {
		permutation[pick] = i + 1;
		makePermutation(n, m, permutation, pick + 1);
	}
}

void printPermutation(int m, int* permutation) {
	for (int i = 0; i < m; i++)
		cout << permutation[i] << ' ';
	cout << '\n';
}
