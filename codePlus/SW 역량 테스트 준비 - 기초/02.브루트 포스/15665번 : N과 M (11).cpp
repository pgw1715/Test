#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermutation(vector<vector<int>>&, vector<int>&, int*, int, int, int);
void printUniqueList(vector<vector<int>>&);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin>>n>>m;
	vector<int> numList;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		numList.push_back(num);
	}
	sort(numList.begin(), numList.end());

	vector<vector<int>> uniqueList;
	int permutation[7];
	makePermutation(uniqueList, numList, permutation, n, m, 0);

	sort(uniqueList.begin(), uniqueList.end());
	uniqueList.erase(unique(uniqueList.begin(), uniqueList.end()), uniqueList.end());
	printUniqueList(uniqueList);
	return 0;
}

void makePermutation(vector<vector<int>>& uniqueList, vector<int>& numList, int* permutation, int n, int m, int pick){
	if(pick == m){
		vector<int> tmp;
		for(int i=0;i<m;i++){
			tmp.push_back(permutation[i]);
		}
		uniqueList.push_back(tmp);
		return;
	}
	for(int i=0;i<n;i++){
		permutation[pick] = numList[i];
		makePermutation(uniqueList, numList, permutation, n, m, pick+1);
	}
}

void printUniqueList(vector<vector<int>>& uniqueList){
	for(int i=0;i<uniqueList.size();i++){
		for(int j=0;j<uniqueList[i].size();j++){
			cout<<uniqueList[i][j]<<' ';
		}
		cout<<'\n';
	}
}
