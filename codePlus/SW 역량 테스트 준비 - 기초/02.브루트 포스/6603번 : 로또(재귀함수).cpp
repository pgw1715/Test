#include <stdio.h>
#include <vector>

using namespace std;

void makeLotto(vector<vector<int>>&, vector<int>&, int, vector<int>&);
void printAnswer(vector<vector<int>>&);

int main() {
	vector<vector<int>> answerList;
	while (true) {
		vector<int> numList;
		int k, s;
		scanf("%d", &k);
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			scanf("%d", &s);
			numList.push_back(s);
		}
		vector<int> tmpList;
		makeLotto(answerList, numList, 0, tmpList);
		vector<int> newLine;
		newLine.push_back(0);
		answerList.push_back(newLine);
	}
	printAnswer(answerList);
	return 0;
}

void makeLotto(vector<vector<int>>& answerList, vector<int>& numList, int idx, vector<int>& tmpList) {
	if (tmpList.size() == 6) {
		answerList.push_back(tmpList);
		return;
	}
	if (idx >= numList.size())
		return;

	tmpList.push_back(numList[idx]);
	makeLotto(answerList, numList, idx + 1, tmpList);
	tmpList.pop_back();
	makeLotto(answerList, numList, idx + 1, tmpList);
}

void printAnswer(vector<vector<int>>& answerList) {
	for (int i = 0; i < answerList.size(); i++) {
		if (answerList[i].size() == 1)
			printf("\n");
		else {
			for (int j = 0; j < answerList[i].size(); j++) {
				printf("%d ", answerList[i][j]);
			}
			printf("\n");
		}
	}
}
