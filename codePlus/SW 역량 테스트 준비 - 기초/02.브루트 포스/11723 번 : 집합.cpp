// cout<<endl   <- endl 이새끼 존나 개짜증나네; 이새끼 때문에 시간초과 존나뜸. '\n' 쓰자 ;
// 좆같은 scanf_s 버리고 
// ios_base::sync_with_stdio(false);
// cin.tie(nullptr);
// 이거쓰자
//toggle 은 s = s ^ (1 << n); 이렇게 쓸 수도 있다.


#include <iostream>

using namespace std;

void add(int, int*);
void remove(int, int*);
void check(int, int*);
void toggle(int, int*);
void all(int*);
void empty(int*);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m;
	cin >> m;
	int s = 0;
	for (int i = 0; i < m; i++) {
		string str;
		int n;
		cin >> str;

		if (str =="add") {
			cin >> n;
			add(n, &s);
		}
		else if (str == "remove") {
			cin >> n;
			remove(n, &s);
		}
		else if (str == "check") {
			cin >> n;
			check(n, &s);
		}
		else if (str == "toggle") {
			cin >> n;
			toggle(n, &s);
		}
		else if (str == "all")
			all(&s);
		else
			empty(&s);
	}
	return 0;
}

void add(int n, int* s) {
	*s = *s | (1 << n);
}

void remove(int n, int* s) {
	*s = *s & (~(1 << n));
}

void check(int n, int* s) {
	if ((*s & (1 << n)) == 0)
		cout << 0 << '\n';
	else
		cout << 1 << '\n';
}

void toggle(int n, int* s) {
	if ((*s & (1<<n)) == 0)
		add(n, s);
	else
		remove(n, s);
}

void all(int* s) {
    *s = (1 << 21) - 1;
}

void empty(int* s) {
	*s = 0;
}
