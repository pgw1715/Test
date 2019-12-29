/*
    POINT : 괄호는 한번만 쓸 수 있는게 아님.
    나동빈은 if (str[i] == '+' || str[i] == '-') 여기에 str[i] == '\0' 를 추가해서 마지막 숫자도 같이 처리되게 함
*/

#include <iostream>
#include <string>

using namespace std;

string str;

int getMin();

int main() {
	cin >> str;

	cout << getMin();
	return 0;
}

int getMin() {
	string number = "";
	int result = 0;
	bool minus = false;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {

			if (minus == false)
				result += stoi(number);
			else
				result -= stoi(number);

			if (str[i] == '-') {
				minus = true;
			}

			number = "";
		}
		else
			number += str[i];
	}

	if (minus == false)
		result += stoi(number);
	else
		result -= stoi(number);

	return result;
}
