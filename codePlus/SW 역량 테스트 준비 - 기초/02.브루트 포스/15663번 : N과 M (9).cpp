// vector 중복제거 익히기
// 중복 제거 전에는 정렬을 한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermutation(vector<vector<int>>&, vector<int>&, int*, bool*, int, int, int);
void printUniqueList(vector<vector<int>>&);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> numList;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		numList.push_back(num);
	}
	sort(numList.begin(), numList.end());  //뒤에서 중복제거를 위해 정렬을 한번 더 해야되므로 여기서는 순열만들때 정렬이 꼭 필요한게 아니라면 굳이 할 필요는 없다.

	vector<vector<int>> uniqueList;
	int permutation[8];
	bool check[8] = {false,};

	makePermutation(uniqueList, numList, permutation, check, n, m, 0);

	sort(uniqueList.begin(), uniqueList.end()); 
	uniqueList.erase(unique(uniqueList.begin(), uniqueList.end()), uniqueList.end());

	printUniqueList(uniqueList);
	return 0;
}

void makePermutation(vector<vector<int>>& uniqueList, vector<int>& numList, int* permutation, bool* check, int n, int m, int pick){
	if(pick == m){
		vector<int> tmp;
		for(int i=0;i<m;i++){
			tmp.push_back(permutation[i]);
		}
		uniqueList.push_back(tmp);
		return;
	}
	for(int i=0;i<n;i++){
		if(check[i]) continue;
		permutation[pick] = numList[i];
		check[i] = true;
		makePermutation(uniqueList, numList, permutation, check, n, m, pick+1);
		check[i] = false;
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
