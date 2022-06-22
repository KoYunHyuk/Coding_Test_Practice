#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	map<string, string> m;

	string str1, str2;
	for (int i = 0; i < N; i++) {
		cin >> str1 >> str2;

		m[str1] = str2;
	}

	for (int i = 0; i < M; i++) {
		cin >> str1;
		if (m[str1] != "") {
			cout << m[str1] << "\n";
		}
	}
}