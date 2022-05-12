#include <iostream>
#include <string>
#include <queue>

using namespace std; // S3

int result = 0;

void DFS(int n, int cur) {
	if (n == cur) {
		result++;
		return;
	}

	if (cur + 1 <= n) {
		DFS(n, cur + 1);
	}
	if (cur + 2 <= n) {
		DFS(n, cur + 2);
	}
	if (cur + 3 <= n) {
		DFS(n, cur + 3);
	}
}

int main() {
	int test_case;
	cin >> test_case;

	while (test_case--) {
		int n;
		cin >> n;

		result = 0;
		DFS(n, 0);
		cout << result << "\n";
	}
}