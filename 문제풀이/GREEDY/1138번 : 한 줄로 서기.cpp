/*
입력으로 받는 v 배열이 의미하는 것 : result 배열 앞에 빈칸 n개를 남겨놓아라!
ex) v[1] = 2 면, result = ㅁㅁ2ㅁㅁㅁ...  
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

vector<int> result;

void setResult();
void showResult();
int getIdx(int);

int main() {
	int personCnt;
	cin >> personCnt;

	for (int i = 0; i < personCnt; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	for (int i = 0; i < personCnt; i++)
		result.push_back(0);

	setResult();
	showResult();

	return 0;
}

void setResult() {
	result[v[0]] = 1;
	for (int i = 1; i <= v.size() - 1; i++) {
		result[getIdx(v[i])] = i + 1;
	}
}

int getIdx(int x) {
	int n = 0;
	int i = 0;
	for (i = 0; i < result.size(); i++) {
		if (n == x)
			break;

		if (result[i] == 0)
			n++;

	}
	while (true) {
		if (result[i] != 0)
			i++;
		else
			break;
	}

	return i;
}

void showResult() {
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}
