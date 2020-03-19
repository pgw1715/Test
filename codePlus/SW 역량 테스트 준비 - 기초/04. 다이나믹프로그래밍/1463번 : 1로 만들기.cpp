#include <iostream>
#include <cstring>

#define MAX 1000001

using namespace std;

int ans[MAX];

void d(int);

int main() {
	int n;
	cin >> n;
	memset(ans, 0, sizeof(ans));
	d(n);
	cout << ans[1] << '\n';
	return 0;
}

void d(int n) {
	if (n == 1) return;
	if (n % 3 == 0) {
		if (ans[n / 3] == 0) {
			ans[n / 3] = ans[n] + 1;
			d(n / 3);
		}
		else {
			if (ans[n / 3] > ans[n] + 1) {
				ans[n / 3] = ans[n] + 1;
				d(n / 3);
			}
		}
	}
	if (n % 2 == 0) {
		if (ans[n / 2] == 0) {
			ans[n / 2] = ans[n] + 1;
			d(n / 2);
		}
		else {
			if (ans[n / 2] > ans[n] + 1) {
				ans[n / 2] = ans[n] + 1;
				d(n / 2);
			}
		}
	}
	if (ans[n - 1] == 0) {
		ans[n - 1] = ans[n] + 1;
		d(n - 1);
	}
	else {
		if (ans[n - 1] > ans[n] + 1) {
			ans[n - 1] = ans[n] + 1;
			d(n - 1);
		}
	}
}
