// cin, cout 써서 별지랄을 다해도 시간초과더니 scanf, printf 쓰니까 바로됨...
// 무한으로 입력받을 때는 cin, cout 쓰지말자 ;

#include <stdio.h>
#include <vector>

using namespace std;

bool chae[1000001];
vector<int> numberList;
vector<int> primeList;
void setChae();

int main(){
	while(true){
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		numberList.push_back(n);
	}

	setChae();

	for(int i=0;i<numberList.size();i++){
		for(int j=1;j<primeList.size();j++){
			int prime2 = numberList[i] - primeList[j];
			if(chae[prime2]==false){
				printf("%d = %d + %d\n",numberList[i], primeList[j], prime2);
				break;
			}
		}
	}

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
