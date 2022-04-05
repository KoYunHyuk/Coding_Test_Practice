#include <iostream>
#include <vector>
#include <string>

using namespace std; // S2

int main() {
	string str;
	cin >> str;
	string temp = "";
	int result = 0;

	bool minus = false;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus) {
				result -= stoi(temp);
			}
			else {
				result += stoi(temp);
			}

			temp = "";
			if (str[i] == '-') {
				minus = true;
			}
		}
		else {
			temp += str[i];
		}
	}

	cout << result;
	return 0;
}