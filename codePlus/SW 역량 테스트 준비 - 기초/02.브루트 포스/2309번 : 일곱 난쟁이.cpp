#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int heightList[9];
	int heightSum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &heightList[i]);
		heightSum += heightList[i];
	}

	sort(heightList, heightList + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (i == j)
				continue;
			if (heightSum - heightList[i] - heightList[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)
						continue;
					printf("%d\n", heightList[k]);
				}
				return 0;
			}
		}
	}
	return 0;
}
