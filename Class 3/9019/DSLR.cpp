#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std; // G5

int a, b;
bool visited[10000];

void BFS() {
	queue<pair<int, string>> q; // string : 변화중인 숫자 , int : 연산 횟수
	q.push({ a, "" });
	visited[a] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string result = q.front().second;
		q.pop();

		if (num == b) {
			cout << result << "\n";
			return;
		}

		// D
		int D = (num * 2) % 10000;
		if (!visited[D]) {
			visited[D] = true;
			q.push({ D, result + "D" });
		}

		// S
		int S = num - 1 < 0 ? 9999 : num - 1;
		if (!visited[S]) {
			visited[S] = true;
			q.push({ S, result + "S" });
		}

		// L
		int L = (num % 1000) * 10 + (num / 1000);
		if (!visited[L]) {
			visited[L] = true;
			q.push({ L, result + "L" });
		}

		// R
		int R = num / 10 + (num % 10) * 1000;
		if (!visited[R]) {
			visited[R] = true;
			q.push({ R, result + "R" });
		}
	}
}

int main() {
	// n = ((d1 × 10 + d2) × 10 + d3) × 10 + d4
	// D : 2n % 10000, S : n - 1, L : Left Shift , R : Right Shift
	int test_case;
	cin >> test_case;

	while (test_case--) {
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		BFS();
	}
}