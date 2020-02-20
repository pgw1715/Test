// n과 k 가 같은 수로 입력되었을 때를 생각해야됨..

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int bfs(int,int);
bool check[100001];

int main(){
	int n,k;
	cin>>n>>k;

	if(n==k){
		cout<<0<<'\n';
		return 0;
	}

	memset(check, false, sizeof(check));	
	cout<<bfs(n,k)<<'\n';
	return 0;
}

int bfs(int n, int k){
	queue<pair<int,int>> q;
	q.push(make_pair(n,0));
	check[n] = true;
	while(!q.empty()){
		pair<int,int> pos = q.front();
		q.pop();
		if(pos.first+1 <=100000 && !check[pos.first+1]){
			if(pos.first+1 == k) return pos.second+1;
			q.push(make_pair(pos.first+1, pos.second+1));
			check[pos.first+1] = true;
		}
		if(pos.first-1 >= 0 && !check[pos.first-1]) {
			if(pos.first-1 == k) return pos.second+1;
			q.push(make_pair(pos.first-1, pos.second+1));
			check[pos.first-1] = true;
		}
		if(pos.first*2<=100000 && !check[pos.first*2]) {
			if(pos.first*2 == k) return pos.second+1;
			q.push(make_pair(pos.first*2, pos.second+1));
			check[pos.first*2] = true;
		}
	}

}
