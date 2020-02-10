#include <iostream>

using namespace std;

void makePermutation(int, int, int, int*, bool*);
void printPermutation(int*, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	int permutation[8];
	bool check[8] = {false,};
	makePermutation(0, n, m, permutation, check);
	return 0;
}

void makePermutation(int idx, int n, int m, int* permutation, bool* check) {
	if (idx == m) {
		printPermutation(permutation, m);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		permutation[idx] = i + 1;
		check[i] = true;
		makePermutation(idx + 1, n, m, permutation, check);
		check[i] = false;
	}
}

void printPermutation(int* permutation, int m) {
	for (int i = 0; i < m ;i++) {
		cout << permutation[i] << ' ';
	}
	cout << '\n';
}
