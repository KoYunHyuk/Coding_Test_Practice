#include <iostream>
#include <vector>
#include <string>

using namespace std; // S1

int N, M;
string str;

int main() {
	cin >> N >> M >> str;
	string P = "";


	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		int k = 0;
		if (str[i] == 'I') {
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				k++;
				if (k == N) {
					result++;
					k--;
				}
				i += 2;
			}

		}
	}
	cout << result;

}