#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> alphaList;
vector<string> answerList;
int l,c;
void printAnswerList();
void makeAnswerList(string, int);

int main(){
	scanf("%d %d",&l,&c);

	for(int i=0;i<c;i++){
		char alpha;
		cin>>alpha;
		alphaList.push_back(alpha);
	}

	sort(alphaList.begin(), alphaList.end());

	makeAnswerList("", 0);
	printAnswerList();

	return 0;
}

void makeAnswerList(string password, int idx){
	if(l == password.length()){
		answerList.push_back(password);
		return;
	}
	if(c <= idx)
		return;
	makeAnswerList(password+alphaList[idx], idx+1);
	makeAnswerList(password, idx+1);
}

void printAnswerList(){
	for(int i=0;i<answerList.size();i++){
		int ja = 0, mo = 0;
		for(int j=0;j<l;j++){
			if(answerList[i][j] == 'a' || answerList[i][j] == 'e' || answerList[i][j] == 'i' || answerList[i][j] == 'o' || answerList[i][j] == 'u')
				mo++;
			else
				ja++;
			if(ja>=2 && mo>=1){
				cout<<answerList[i]<<endl;
				break;
			}
		}
	}
}

