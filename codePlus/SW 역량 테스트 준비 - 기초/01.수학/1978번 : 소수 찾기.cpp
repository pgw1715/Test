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
	chae[1] = true;
	int n = 2;
	while(n*n<=1000){
		if(chae[n]==true){
			n++;
			continue;
		}
		for(int i = n+1;i<=1000;i++){
			if(i%n==0){
				chae[i] = true;
			}
		}
		n++;
	}
}
