#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int getMaxWeight();

int main() {
	int rowCnt;

	cin >> rowCnt;
	for (int i = 0; i < rowCnt; i++) {
		int weight;
		cin >> weight;
		v.push_back(weight);
	}

	sort(v.begin(), v.end());

	cout << getMaxWeight();
	
	return 0;
}

int getMaxWeight() {
	int maxWeight = 0;
	for (int i = 0; i < v.size(); i++) {
		int weight = v[i] * (v.size() - i);
		if (maxWeight < weight)
			maxWeight = weight;
	}

	return maxWeight;
}
