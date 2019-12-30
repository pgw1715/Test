#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;

int passCnt[20] = {0};
void printResult()

int main(){
	int testcaseCnt;
	cin>>testcaseCnt;

	for(int i=0;i<testcaseCnt;i++){
		int pairCnt;
		cin>>pairCnt;
		for(int j=0;j<pairCnt;j++){
			int a,b;
			cin>>a>>b;
			v.push_back(make_pair(a,b));
		}

		passCnt[i] = getPassCnt();
	}

	printResult();
}

int getPassCnt(){

}
