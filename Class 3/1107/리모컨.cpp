#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int ary[10]; // 고장난 번호 = true

bool check(int now) {
	string str = to_string(now);
	for (int i = 0; i < str.length(); i++) {
		if (ary[str[i] - 48]) return false;
	}
	return true;
}

int main() {
	cin >> N >> M;

	int num;
	for (int i = 0; i < M; i++) {
		cin >> num;
		ary[num] = 1;
	}

	string str = to_string(N);

	int minimum = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			int tmp = abs(N - i) + to_string(i).length();
			minimum = min(minimum, tmp);
		}
	}

	cout << minimum << endl;

	return 0;
}