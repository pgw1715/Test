#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int getTotal(int);

int main(){
	int count;
	int wait;
	cin>>count;
	for(int i=0;i<count;i++){
		cin>>wait;
		v.push_back(wait);
	}
	sort(v.begin(),v.end());

	cout<<getTotal(count);
	return 0;
}

int getTotal(int n){
	int sum = 0;
	for(int i=0;i<v.size();i++){
		sum += n * v[i];
		n--;
	}
	return sum;
}