/*
  응 개털렸어~ 
*/

#include <stdio.h>
#include <vector>

using namespace std;

int n, k;
vector<char> v;

int main(){
	scanf("%d %d",&n, &k);
	getchar();
	int delCnt = 0;
	for(int i=0;i<n;i++){
		char a;
		scanf("%c", &a);
		while(delCnt < k && v.size() != 0 && v.back() < a){
			v.pop_back();
			delCnt++;
		}
		v.push_back(a);

	}

	while(delCnt<k){
		v.pop_back();
		delCnt++;
	}

	for(int i=0;i<v.size();i++)
		printf("%c",v[i]);
}

/*
  백터로 스텍을 이용해서 푸는 방법은 생각도못함.
  백터로 스택이용해서 풀어도 시간초과떴었는데
  더러운 코드를 간단히하니까 시간초과안뜸;;
*/
