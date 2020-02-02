// 나중에 DP로 풀어보기

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> list;

int main() {
	int testcaseCnt;
	scanf("%d", &testcaseCnt);
	for (int i = 0; i < testcaseCnt; i++) {
		int n;
		scanf("%d", &n);
		list.push_back(n);
	}
	int anserCnt;
	for (int i = 0; i < testcaseCnt; i++) {
		anserCnt = 0;
		for (int i1 = 1; i1 <= 3; i1++) {
			if (i1 == list[i])
				anserCnt++;
			for (int i2 = 1; i2 <= 3; i2++) {
				if (i1+i2 == list[i])
					anserCnt++;
				for (int i3 = 1; i3 <= 3; i3++) {
					if (i1+i2+i3 == list[i])
						anserCnt++;
					for (int i4 = 1; i4 <= 3; i4++) {
						if (i1 + i2 + i3 + i4 == list[i])
							anserCnt++;
						for (int i5 = 1; i5 <= 3; i5++) {
							if (i1 + i2 + i3 + i4 + i5 == list[i])
								anserCnt++;
							for (int i6 = 1; i6 <= 3; i6++) {
								if (i1 + i2 + i3 + i4 + i5 + i6 == list[i])
									anserCnt++;
								for (int i7 = 1; i7 <= 3; i7++) {
									if (i1 + i2 + i3 + i4 + i5 + i6 + i7 == list[i])
										anserCnt++;
									for (int i8 = 1; i8 <= 3; i8++) {
										if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 == list[i])
											anserCnt++;
										for (int i9 = 1; i9 <= 3; i9++) {
											if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 == list[i])
												anserCnt++;
											for (int i10 = 1; i10 <= 3; i10++) {
												if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 == list[i])
													anserCnt++;

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", anserCnt);
	}
	return 0;
}
