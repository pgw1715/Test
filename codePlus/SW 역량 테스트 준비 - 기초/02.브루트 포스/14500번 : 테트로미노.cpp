#include <stdio.h>

#define MAXSIZE	501

using namespace std;

int main() {
	int map[MAXSIZE][MAXSIZE];
	int n, m;
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}

	int sum = 0;
	int maxSum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j + 3 <= m) { // 1번 도형
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 3 <= n) { // 2번 도형
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 1 <= m) { // 3번 도형
				sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
				if(sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //4번
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //5
				sum = map[i + 2][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //6
				sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //7
				sum = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //8
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //9
				sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //10
				sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //11
				sum = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //12
				sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //13
				sum = map[i + 1][j] + map[i + 2][j] + map[i][j + 1] + map[i + 1][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //14
				sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //15
				sum = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i][j + 2];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //16
				sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i][j + 2];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 1 <= n && j + 2 <= m) { //17
				sum = map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //18
				sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
			if (i + 2 <= n && j + 1 <= m) { //19
				sum = map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (sum > maxSum) maxSum = sum;
			}
		}
	}
	printf("%d\n", maxSum);
}
