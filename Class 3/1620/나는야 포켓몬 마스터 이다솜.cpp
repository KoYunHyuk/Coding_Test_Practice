#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>

using namespace std; // S4

int N, M;
map<string, string> m1;
map<string, string> m2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;

		m1.insert({ str, to_string(i) });
		m2.insert({ to_string(i), str });
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;

		if (m1.find(str) != m1.end()) {
			cout << m1.find(str)->second << "\n";
		}
		else {
			cout << m2.find(str)->second << "\n";
		}
	}
}