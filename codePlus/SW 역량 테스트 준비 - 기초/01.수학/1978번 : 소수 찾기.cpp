// "에라토스테네스의 체"를 이용해서 품

#include <iostream>

using namespace std;

bool chae[1001];

void setChae();

int main(){
	setChae();

	int cnt;
	cin>>cnt;
	int primeCnt = 0;
	for(int i=0;i<cnt;i++){
		int n;
		cin>>n;
		if(chae[n]==false)
			primeCnt++;
	}
	
	cout<<primeCnt;

	return 0;
}

void setChae(){
	chae[0] = chae[1] = true;
	for(int n = 2;n<=1000000;n++){
		if(chae[n] == true)
			continue;
		primeList.push_back(n);
		for(int i = 2*n;i<=1000000;i+=n){
			chae[i] = true;
		}
	}
}
