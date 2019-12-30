/*
  맨처음 string number 를 전역변수로 줬더니 런타임 에러가 뜸.  전역변수에 너무많은 데이터가 들어가서 그런듯..
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int numCnt[9] = {0};
int sum = 0;

void setNumCnt(string);
bool isPossible();
bool compare(int,int);

int main(){
	string number;
	cin>>number;

	setNumCnt(number);
	if(isPossible()){
		sort(number.begin(), number.end(), compare);
		cout<<number;
	}
	else{
		cout<<-1;
	}
	return 0;
}


void setNumCnt(string number){
	for(int i=0;i<number.size();i++){
		numCnt[number[i] - '0'] ++;
		//sum += number[i] - '0';  -- 나동빈은 여기 이걸 추가해서 반복문을 한번돌때 sum도 계산되도록 함...
	}
}

bool isPossible(){
	if(numCnt[0] == 0)
		return false;

	for(int i=0;i<10;i++)
		sum += numCnt[i]*i;

	if(sum % 3 != 0)
		return false;

	return true;
}

bool compare(int a, int b){
	if(a>b)
		return a>b;
	else
		return b<a;
}
