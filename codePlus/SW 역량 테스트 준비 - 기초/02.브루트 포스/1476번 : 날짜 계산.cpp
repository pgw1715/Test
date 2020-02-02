// 왜 마지막에 i에 +1을 해서 출력하는지 깔끔하게 이해가안됨;

#include <stdio.h>

using namespace std;

int main() {
	int E, S, M;
	scanf_s("%d %d %d", &E, &S, &M);
	int maxYear = 15 * 28 * 19;

	for (int i = 0; i <= maxYear; i++) {
		if (i%15 == E-1 && i%28 == S-1 && i%19 == M-1) {
			printf("%d\n",i+1);
			return 0;
		}
	}
	return 0;
}
