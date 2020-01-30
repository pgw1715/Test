// 유클리드 호제법을 통해 최대공약수(GCD) 구하기
// GCD를 이용해 최소공배수(LCM) 구하기

#include <iostream>

using namespace std;

int getGCD(int,int);
int getLCM(int,int);

int main(){
	int num1, num2;
	cin>>num1>>num2;

	cout<<getGCD(num1,num2)<<endl;
	cout<<getLCM(num1,num2)<<endl;

	return 0;
}

int getGCD(int num1, int num2){
	int a,b;
	if(num1>num2){
		a = num1;
		b = num2;
	}
	else{
		a = num2;
		b = num1;
	}

	while(b != 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int getLCM(int num1, int num2){
	return num1*num2/getGCD(num1,num2);
}
