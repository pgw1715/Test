//재귀함수로 문제풀때 접근방법
// 1. 성공하는 경우
// 2. 실패하는 경우
// 3. 다음경우
// 위 3가지를 각각 코드로 구현.  순서가 바뀜에 따라 결과가 다를 수 있음.

#include <stdio.h>
#include <vector>

using namespace std;

int getPossibleCnt(int, int, int);

int main(){
	vector<int> list;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		list.push_back(n);
	}

	for(int i=0;i<t;i++){
		printf("%d\n", getPossibleCnt(0,0,list[i]));
	}

	return 0;
}

int getPossibleCnt(int sum, int idx, int goal){
	if(sum == goal)
		return 1;
	if(idx>goal)
		return 0;
	return getPossibleCnt(sum+1, idx+1, goal) + getPossibleCnt(sum+2, idx+2, goal) + getPossibleCnt(sum+3, idx+3, goal);
}

//1. 성공하는 경우 : sum = goal
//2. 실패하는 경우 : idx > goal
//3. 다음경우 : 1선택한경우 + 2선택한 경우 + 3선택한 경우
