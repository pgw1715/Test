/*
  n번째 숫자가 첫번째 ~ n-1번째 숫자를 모두 더한 것 보다 작으면 첫 ~ n-1번째 숫자들로 n번째 숫자를 표현할 수 있음.. 이건 몰랐음
*/
#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];

int getMin(int);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	cout << getMin(n);
	return 0;
}

int getMin(int n) {
	int i;
	int std = 1;
	for (i = 0; i < n; i++) {
		if (std < a[i])
			break;
		std += a[i];
	}

	return std;
}
