#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std; // G5

int T, N;
string p, str; // p - 수행할 함수, str - parsing을 위한 변수


int main() {
	cin >> T;

	while (T--) {
		deque<int> dq;
		string s = "";

		cin >> p >> N >> str;

		for (int i = 0; i < str.size(); i++) {
			if (isdigit(str[i])) {
				s += str[i];
			}
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}

		bool reverse = false; // 0: 원본, 1: Reverse
		bool isEmpty = false;

		for (auto k : p) {
			if (k == 'R') { // reverse
				reverse = !reverse;
			}
			else { // pop
				if (!dq.empty()) {
					if (reverse == false) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
				else {
					cout << "error" << endl;
					isEmpty = true;
					break;
				}
			}
		}

		if (isEmpty == true) continue;

		cout << "[";
		while (!dq.empty()) {
			if (reverse == false) {
				cout << dq.front();
				dq.pop_front();
				if (!dq.empty()) cout << ",";
			}
			else {
				cout << dq.back();
				dq.pop_back();
				if (!dq.empty()) cout << ",";
			}
		}
		cout << "]\n";
	}
}