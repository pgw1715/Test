#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermutation(vector<vector<int>>&, vector<int>&, vector<int>&, int, int, int, int);
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

	vector<int> permutation;
	vector<vector<int>> uniqueList;
	makePermutation(uniqueList, numList, permutation, 0, 0, n, m);

	sort(uniqueList.begin(), uniqueList.end());
	uniqueList.erase(unique(uniqueList.begin(), uniqueList.end()), uniqueList.end());
	printUniqueList(uniqueList);
	return 0;
}

void makePermutation(vector<vector<int>>& uniqueList, vector<int>& numList, vector<int>& permutation, int idx, int pick, int n, int m){
	if(pick == m){
		uniqueList.push_back(permutation);
		return;
	}
	if(idx >= n)
		return;
	permutation.push_back(numList[idx]);
	makePermutation(uniqueList, numList, permutation, idx+1, pick+1, n, m);
	permutation.pop_back();
	makePermutation(uniqueList, numList, permutation, idx+1, pick, n, m);
}

void printUniqueList(vector<vector<int>>& uniqueList){
	for(int i=0;i<uniqueList.size();i++){
		for(int j=0;j<uniqueList[i].size();j++){
			cout<<uniqueList[i][j]<<' ';
		}
		cout<<'\n';
	}
}
