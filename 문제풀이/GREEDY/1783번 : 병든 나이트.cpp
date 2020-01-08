/*
  참패..  문제 이해하기가 쉬운 것 같지만 어려움. 문제 이해만 제대로하면 약간의 노가다로 풀수있음
*/

#include <iostream>

using namespace std;

int getMaxCnt(int,int);

int main(){
	int x,y;
	cin>>y>>x;

	cout<<getMaxCnt(x,y);

	return 0;
}

int getMaxCnt(int x, int y){
	if(x == 1 || y == 1)
		return 1;
	
	if(y==2){
		if(x==2)
			return 1;
		else if(x==3)
			return 2;
		else if(x==4)
			return 2;
		else if(x==5 || x==6)
			return 3;
		else
			return 4;
	}
	else {
		if(x==2)
			return 2;
		else if(x==3)
			return 3;
		else if(x==4)
			return 4;
		else if(x==5)
			return 4;
		else if(x==6)
			return 4;
		else
			return x-2;
	}

}
