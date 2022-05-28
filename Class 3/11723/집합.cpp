#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N;
int ary[21];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;

	string str;
	int x;
	while (N--) {
		cin >> str;

		if (str == "add") {
			cin >> x;
			if (ary[x] == 0) {
				ary[x] = 1;
			}
		}
		else if (str == "remove") {
			cin >> x;
			if (ary[x] == 1) {
				ary[x] = 0;
			}
		}
		else if (str == "check") {
			cin >> x;
			if (ary[x] == 1) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (str == "toggle") {
			cin >> x;
			if (ary[x] == 1) {
				ary[x] = 0;
			}
			else {
				ary[x] = 1;
			}
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				ary[i] = 1;
			}
		}
		else {
			memset(ary, 0, sizeof(ary));
		}

	}
}