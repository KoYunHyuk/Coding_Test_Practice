#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std; // S4

int N, M;
set<string> s;
priority_queue<string, vector<string>, greater<string>> pq;

int main() {
	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (s.find(str) != s.end()) {
			pq.push(str);
		}
	}

	cout << pq.size() << endl;
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}